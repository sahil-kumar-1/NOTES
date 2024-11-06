Messaging system : transferring data from one application to another.

types : 
    
    point to point : 
        messages are persisted in a queue. 
        One or more consumers can consume the messages in the queue, 
        but a particular message can be consumed by a maximum of one consumer only. 
        Once a consumer reads a message in the queue, it disappears from that queue.

           eg: order processing system

    publish-subscribe (pub-sub) messaging system :
        messages are persisted in a topic.
        consumers can subscribe to one or more topic and consume all the messages in that topic.

          message producers -> publishers 
          message consumers -> subscribers.

          eg: dish Tv -- publishes different channels and  anyone can subscribe to their own set of channels and get them whenever their subscribed channels are available.

          Kafka is a distributed publish-subscribe messaging system,  handles high amount of real time data feeds.


/*   

                    Terms :                        */ 


page cache : component of the operating system`s memory management system.
             It is used to cache pages of files that have been recently read or written.

network socket : endpoint for sending or receiving data across a computer network. 
                 It provides an abstraction for network communication and enables processes on different devices to communicate with each other. 
                 Sockets use the Internet Protocol (IP) and Transmission Control Protocol (TCP) or User Datagram Protocol (UDP) for communication.             

Topics : 

        A stream of messages belonging to a particular category is called a topic, Data is stored in topics.
        Topics are split into partitions.

        In Apache Kafka, topics are identified by their names. 
        A Kafka topic is essentially a named stream or feed to which producers write messages and from which consumers read messages. 
        The topic name serves as a unique identifier for a specific stream of data.

partitions: 

        A Kafka topic is divided into partitions. Each partition is an ordered, immutable sequence of records.
        Partitions are the basic unit of parallelism and distribution in Kafka. 
        They allow multiple producers and consumers to work on different subsets of data concurrently.
        The number of partitions in a topic determines the level of parallelism and the maximum number of consumers that can read from the topic simultaneously.
        A partition is implemented as a set of segment files of equal sizes

Offset :

        Every message within a partition is assigned a unique identifier called an "offset." 
        The offset is a sequential number that represents the position of a message within a partition.
        Offsets start from 0 and increase monotonically with each new message.
        Consumers use offsets to keep track of their position in a partition. When a consumer reads messages from a partition, it specifies the offset from which it wants to start reading.

Segment Files:

        Each partition is implemented as a set of segment files. 
        A segment file is a physical file on disk that stores a portion of the partition`s data.
        each segment is written to a separate file.
        Kafka uses a segment-based storage model. 

        segment files within a partition are of equal sizes (maximum size which is configurable).
        When a segment reaches its maximum size, a new segment file is created to store additional data.

        Log Compaction:

           Kafka supports a feature called log compaction, where only the latest record for each key is retained in a partition. 
           Segments play a role in log compaction by grouping records with the same key within a segment.

Relationship between Segment and Offset:

        In Kafka, when a message is produced to a partition, it is appended to the active segment, which is the latest segment in the partition.
        The offset of a message is essentially its position within the active segment of the partition.
        As more messages are produced, they are appended to the active segment, and their offsets increase sequentially.
        When the active segment reaches a configurable size limit (e.g., segment.bytes configuration), a new segment is created, and subsequent messages are appended to this new segment. 
        The offset for the first message in the new segment starts from 0 again.

leaders & followers : 

        In the context of Apache Kafka, a distributed streaming platform, the concept of a "leader" node is associated with how data is replicated and managed within Kafka topics. 
        This concept is fundamental to Kafka's design for fault tolerance, scalability, and data durability.

            Here's a breakdown of the key concepts:

           
            Replication:

                    For fault tolerance and durability, each partition has multiple replicas (copies) distributed across different broker nodes in the Kafka cluster.
                    Replicas are designated as either in-sync replicas (ISR), which are up-to-date with the leader, or out-of-sync replicas.
            
            Leader and Followers:

                    Each partition has one leader and multiple followers (replicas).
                    The leader is the node responsible for handling all reads and writes for the partition.
                    Followers replicate the data from the leader.
            
            
            Responsibilities of the Leader:

                    The leader node handles all client reads and writes for a given partition.
                    Producers send messages to the leader, and consumers read messages from the leader.
                    The leader is responsible for managing the ordering of messages within the partition.
            Failover and High Availability:

                    If the leader node for a partition fails, Kafka dynamically and transparently elects a new leader from the in-sync replicas to ensure continuous availability of the partition`s data.
                    This failover process ensures that the system remains available even in the presence of node failures.

        NOTE: in Kafka, the assignment of leaders for partitions is done independently for each partition within a topic. 
              This means that a particular broker can be the leader for some partitions of a topic while being a follower for others.            
            
Brokers : 
            Brokers are simple system responsible for maintaining the pub-lished data. 
            Each broker may have zero or more partitions per topic.     

Kafka Cluster :

        Kafka’s having more than one broker are called as Kafka cluster. 
        A Kafka cluster can be expanded without downtime. These clusters are used to manage the persistence and replication of message data.                   
                
Producers :

        Producers are the publisher of messages to one or more Kafka topics. 
        Producers send data to Kafka brokers. 
        Every time a producer pub-lishes a message to a broker, the broker simply appends the message to a partition ( last segment file ).
        Producer can also send messages to a partition of their choice.

Consumers :

        Consumers read data from brokers. Consumers subscribes to one or more topics and consume published messages by pulling data from the brokers.                         
        a consumer is a client application that subscribes to one or more topics and processes the messages produced to those topics.

ZooKeeper role in kafka ecosystem :

        ZooKeeper is used for managing and coordinating Kafka broker. 
        ZooKeeper service is mainly used to notify producer and consumer about the presence of any new broker in the Kafka system or failure of the broker in the Kafka system. 
        As per the notification received by the Zookeeper regarding presence or failure of the broker then pro-ducer and consumer takes decision and starts coordinating their task with some other broker.        



/*

                        Apache Kafka - WorkFlow                */        


