Aerospike 

/*--------------------------------------------------------------------------------------------------------------------*/
SCHEMALESS DATA MODEL   
    storageEngine : NVme , DRAM, persistent memory. 

    dataModel :

        NameSpace       
        
            - top level data container which contains records and policies like storageEngine used. 
            - records are grouped in sets inside conatiner  // optional 
                - by default sets inherit the polies of container but we can define additional policies.  
            - a DB can have multiple namesapces each with its own policies and storage engine.
            - records which do not belong to the user defined set belong to the nullSet namespace. 

        records :

            - maded of three component       KEY | META_DATA |  BINS (data)

            KEY : unique identifier of the record. 
            META_DATA : generation counter , time to live , last updated time. 
            BINS : bins is where actual data is.

                    - single record can store multiple bins & datatype.
                    - data type is defined by the value within the bin.

/*--------------------------------------------------------------------------------------------------------------------*/

DATA DIStribution

  -   aerospike uses Share Nothing Architecture. 

        A "Shared Nothing Architecture" is a design principle commonly used in distributed systems, particularly in database systems and big data processing frameworks. In this architecture, each node (or server) in the system operates independently and does not share memory or disk storage with other nodes.

        Here are some key characteristics of a Shared Nothing Architecture:

            Independence: Each node operates independently and does not rely on other nodes for processing or storage.

            Isolation: Nodes are isolated from each other, meaning that failures or issues with one node do not affect the operation of other nodes.

            Scalability: The architecture is highly scalable because adding more nodes to the system does not require coordination or sharing of resources. This allows for linear scalability as the workload increases.

            Fault Tolerance: By isolating nodes, failures are contained and do not propagate to other parts of the system. This makes the architecture inherently fault-tolerant.

            Performance: Shared Nothing Architectures can achieve high performance because each node can operate independently and in parallel, processing data and serving requests concurrently.

            Data Partitioning: Data is typically partitioned across multiple nodes to distribute the workload evenly and avoid hotspots. Each node is responsible for a subset of the data.

  - aerospike smart Partitions algorithms distribute the data in the cluster. 
        - inside DB each namespce is partitioned in 4096 logical partitiones
        - these partitions are uniformly distributed into the nodes of cluster.  
        - if we want to replicate owr data to increase reliability then we need to define replication factor. 

            replication Factor : how many copies to store.    // generally we keep the replication factor < N i.e number of Nodes. 
            - these replicas are also distributed evenly in cluster. 

       Now that we have NameSpace divided how do we know which partition record is in ?  
       -> 
          - every record has a key 
          - set Name & key Name is hashed using RIPEMD160 cryptographic hashing algo

         RipeMd takes the details & create 20Byte digest 
          - there is nearly 0 % possibility of collision
          - 1st 12 bits are used to determine partion Id where record is stored.
          - by this client get to record in single hop.   


/*----------------------------------------------------------------------------------------------------------------------------*/

Aerospike clustering.

    - in aerospike DB cluster formation is dynamic.
    - aggriment of nodes participating in cluster is maintained using cluster management sub system.
    - when a node leaves or joins it determines the principle node used during cluster changes which then decides & communicates the new cluster membership to which other node agree on. 


Nodes in cluster can communicate using
    - heartbeat 
    - fabric layer
    - tcp/ip 

applications using aerospike api use integrated aerospike smart client 
this allows the application to ignore node management , while the client handles the communication with the clster.
this smart client uses tcp/ip to connect to one of seed node to discver the rest of the cluster.
the client then opens the direct connection pool to each node in the cluster.

in a event if a node unexpectedly goes down -> new one is added OR expected maintainence occurs
other NOdes are quickly able to identify the change & quickly balence & migrate data giving minimal to no impact to our application.
while the cluste is changing the aerospike smart client pulls the node and makes the new partition map as our application carries on. 
this is how samrt client keeps our application logic simple when cluster changes occur. 


/*---------------------------------------------------------------------------------------------------------------------------*/

Succession list

in a name space each partition has a list which defines the order in which the replica order are assigned to nodes  // where the replicas are stored in which node.
this succession list can be computed by all nodes to identify the replica distributed system across the cluster.
rack awereness : forcing the master & replica patition to be stored on different harware failure group. this ensures all partitons including master stays on the separate racks.


succession list is used to prevent data lOss 

 when master or replica leaves the cluster / not-functioning / under maintainence            // suppose master leaves
 new node is assigned its place which sinks the data from existing                           // new node starts sinking data from replica  ---> old replica becomes the master & new node becomes the master.
 the idea is that node with all data needs to be master.

 
 
/*------------------------------------------------------------------------------------------------------------------------------------*/
CRUD operations.

how user application interacts with client library
how client interactg with cluster-server as CRUD operations are processed. 

CREAT
        creating new record stats with user application specifying Namespace, set, key to the client specific bins & data to be stored withing them.
        client hashes the key & setName to create 20 Byte digest 
        from which partitionId for the new record can be derived.
        once partitionId is defined, using the cluster partition map the client is able to send the request in single hop to a node that will own the master copy
        at server a new entry in primary index is created 
            DIGEST | META_DATA | DATA_STORAGE_LOCATION

        the data is then written on master node & node owning replicas.

        at this point data has only been stored in RAM in node
        when write buffer in ram gets full it stores it to peristent storage & flushes. write block also flushes after 1k ms by default to lower the work load. 
        acknowledgement of success is sent back to client.


READ OPERATION

      user application specifies "namespace, set, key " or "metadata" or "namespace & digest" 
      clien user the specified details --> hashes --> partitionId
      client hops to master/replica node/server A/T policy
      at node/server the digest is identified at the primary index of the appropriate record.
      then the requested bins or metadata are returned to client. 


UPDATE 

     user application provides namesapce, seg, key, bins & data 
     client hashes --> partitionId --> server --> identify primary index of appropriate record --> 
     --> record is read & updated with new data. & written to current write block to be sent to new storage location to be written on master & replica 
     success is sent to the client. 
     the original memory location is recovered later during defragmentation  

DELETE 

    functions same as update just no data is stored.

    TTL ( time to live ) can be used for memory management, allowing record expiration & automatic removal after a set duration.
    default TTL in aerospike DB is to live forever. 


/*--------------------------------------------------------------------------------------------------------------------------*/

XDR : aerospike cross data center replication feature.
  
    - asyncrounously replicates the cluster data b/w data centers & is commonly used for desaster recovery, regulatory data locality requirement, content delivery n/w, fast local writes & greater side autonomy. 
    - XDR filter expression defines the record shift b/w the data centers.     ( which namespace/partition/ record )
    - aerospike automatically tracks record last updated time based on write transactions.  LUT
    - XDR tracks records las ship time  : LST 
    - LUT & LST together decides if the record needs to be shiped   ( LUT > LST ---> ship data based on XDR confugration ) : LST is updated after ship
    - these repliaction writes are tracked in event they are needed in cases of node faiulure. 

    - Aerospike supports variety of configurable topology.
         
          active passive topology : 

                 client ---> A ----> B        
                 
                  // client only write to A  | A shifts client write to B  |  B is only used for read 

          active active topology

                 client ----> A <--> B  <--- client 

                 // client can write to any data center | both shift client writes to other.
                 // this topology is not favourable when writes can happen to both data center simultaneously
                //  after aerospike 5.4 bin conversion was introduced to help with potential write conflicts. 
                // bin conversion ensures data is same across the data centers once replication is finished.        

         Star topology.

                A---> B  , A----> C , A----> D

                // one data center ships to mulple data centere, for local reads mostly.       

          BUS topology

               A--->B--->C--->Dapp


     - XDR is able to handle node failure by using redundency single cluster offers                      
     - when communication fails b/w data center time the link went down is recorded & shipping is suspended to the affected data center.
     - once the link is restored shipping restored. 


/*----------------------------------------------------------------------------------------------------------------*/

Consitency VS availability

    - each nameSpace has ability to be configured in two ways prioritising availability or prioritising consistency.

    CAP THEOREM.   ( consistency, availability, partition tolerent)

     Consitency : every read req returns last successfull write or an error.
     Availability : every rew always receives a response without the guarentee that data is current.
     partition tolerent : ensuring cluster availability to continuing working during lost/ delayed communication b/w nodes.

     - in distributed system partition tolerence is always necessary leaving us with choice b/w consistency & availability. 

     AP mode : availabiliy is acheived by replicating the data within cluster.
               writes are poropaged to master & all replicas
               read happens from any one replica genrally master.
               when n/w partition occurs the self managing cluster rebalences & migrates data while reads continue to pull from avilable replica & writes are propagated to all available replicas for the partition. 

    CP mode :   
              guarentee consistency in cost of some un-availability during n/w outage , failure, partitions. 
              cluster needs to define list of nodes known as roaster


/*------------------------------------------------------------------------------------------------------------------*/  

String consistency , flexible reads.
