/*
    install Kubectl   // https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/#install-kubectl-binary-with-curl-on-linux

    install miniKube  // local kubernetes focusing on making it easy to learl and develop for kubernetes.
                      // https://minikube.sigs.k8s.io/docs/start/
     minikube needs docker to be installed for driver 

     minikube start                          // start minikube
     minikube start --driver=docker         // creating cluster using specific driver.
     docker ps              // see all docker processes.
     minikube dashboard      // opens kubernetes dashboard 
     minikube status        // shows the status of node_type, host , kubelet, apiserver, kubeconfig.
     minikube delete        // delete the cluster created by mnikube start.       
 
*/
what is Kubernetes ? 
     Kubernetes (often abbreviated as K8s) is an open-source container orchestration platform that automates the deployment, scaling, and management of containerized applications. 


Need of Kubernetes ?

    apllication up on single server -->  heavy load --> crash/slow-down.  
    what if the only server fails on which application was installed  --> backup ??   
    application running on multiple servers  --> how to mange them  ---> kubernetes comes in picture.

useCases of Kubernetes? 

    Automating deployment
    Management of containerized apps.
    scaling

Kubernetes working overview ? 

    when we set up kubernetes in our infrastructure the two important parts are 
        - master  ( control plane )
            master can be setup in separate node or in one of the worker nodes. 

        - worker nodes 


terms: 

    orchestration : 
      refers to the automated management and coordination of containerized applications and their components across a cluster of machines. 
      Kubernetes acts as an orchestrator, handling tasks such as deployment, scaling, load balancing, service discovery, and health monitoring of containerized applications.

    cluster : group of Nodes/ server. 
              container based applications run inside pods on server.

    Node : server are known as node.              

    pods ? 
      a single instance of running process in a cluster.
      smallest unit inside which container runs.
      it can run one or more container & share the same resource.



Components of K8 master Node. 

    API server : 
        provides interface also known as cubeCtrl for using cubeLets.     
        used to connect with kubelet`s / worker node 

    scheduler : 
        assigns node to newly created pods.            // pod/container will run on which node.

    ETCD :
        key-value store, having all cluster data.

    Control manager :
        responsible for managing the state of the cluster.


Components of K8 worker node.

    kubelet : 
        makes sure that containers are running properly in pods.

    Kube-proxy :
        Maintains network rules for communicating with pods in cluster.

    container-runtime :
        tool responsible for running container // like docker            



kubernetes & docker 

    Kubernetes and Docker are complementary technologies that work together to enable the deployment and management of containerized applications. Here's how Kubernetes uses Docker:

    Container Runtime:
            Kubernetes relies on a container runtime to create and manage containers. 
            Docker is one of the most widely used container runtimes and is the default runtime for many Kubernetes distributions.
            
    Container Image Management:
        Docker provides tools for building, managing, and distributing container images. Kubernetes leverages Docker`s image format and registry to deploy and run containers. 
        Kubernetes can pull container images from Docker Hub, Google Container Registry, or any other container registry that supports the Docker image format.

    Pods and Containers:
        In Kubernetes, containers are deployed and managed within Pods. 
        A Pod is the smallest deployable unit in Kubernetes and represents one or more containers that are scheduled together on the same node. 
        Each container within a Pod is typically created from a Docker image.

    Container Lifecycle Management:
        Kubernetes orchestrates the lifecycle of containers, including creating, starting, stopping, and deleting containers as needed. 
        Kubernetes interacts with the container runtime (e.g., Docker) to manage the lifecycle of containers based on the desired state specified in Kubernetes resources such as Deployments, ReplicaSets, and Pods.

    Container Networking and Storage:
        Kubernetes integrates with Docker`s networking and storage features to provide networking and storage capabilities for containers. 
        Kubernetes assigns IP addresses to Pods, handles container-to-container communication, and provides persistent storage solutions for stateful applications using Docker volumes or other storage plugins.

    Runtime Interface:
        Kubernetes communicates with container runtimes through the Container Runtime Interface (CRI), which provides a standardized interface for managing containers. 
        Docker implements the CRI interface, allowing Kubernetes to interact with Docker and other compatible container runtimes in a consistent manner.

    Overall, Kubernetes and Docker work together to provide a platform for deploying, scaling, and managing containerized applications. While Kubernetes handles orchestration, scheduling, networking, and storage, Docker provides the underlying container runtime and image management capabilities that Kubernetes relies on to deploy and run containers. 

kubernetes & kubectl

    kubectl is the command-line interface (CLI) tool used to interact with Kubernetes clusters. It allows users to execute commands against Kubernetes clusters to create, manage, and monitor resources such as pods, services, deployments, namespaces, and more.

kubernetes & miniKube

    Minikube is a tool that enables you to run a single-node Kubernetes cluster locally on your machine. It`s designed to make it easy to set up and experiment with Kubernetes without needing access to a full-scale production cluster. Minikube creates a virtual machine (usually using a hypervisor like VirtualBox, Hyper-V, or KVM) on your local system and deploys a lightweight Kubernetes cluster within it.

kubernetes & remote registory

    If you are using a local image on a node in a Kubernetes cluster, that local image will only be available for use on that specific node. 
    Kubernetes does not automatically synchronize container images across nodes in the cluster. 
    Each node in the cluster operates independently and manages its own set of containers and container images.

        - Therefore, if you have multiple nodes in your Kubernetes cluster and you want to use the same image on different nodes, you need to ensure that the image is available locally on each node where you want to run containers using that image.

    There are a few approaches you can take to ensure that the image is available on multiple nodes:

        - Build and Distribute Locally: Build the container image locally on each node where you want to use it. This ensures that the image is available locally on each node.

        - Use a Shared File System: Set up a shared file system (e.g., NFS, GlusterFS) that is accessible from all nodes in the cluster. Store the container image on the shared file system, and mount it on each node where you want to use it. This allows all nodes to access the same image from a central location.

        - Push Image to a Registry: Push the local image to a container registry (e.g., Docker Hub, Google Container Registry) where it can be accessed by all nodes in the cluster. 
        Then, when defining Kubernetes resources (e.g., Pods, Deployments), specify the image from the registry. Kubernetes will pull the image from the registry as needed when scheduling pods on different nodes.

    NOTE : Using a container registry is often the most scalable and recommended approach, as it centralizes image management and ensures consistency across the cluster.

/*----------------------------------------------------------------------------------------------*/        
/*--------------------------------  deployment of an APP K8s Deployment  -----------------------*/        
/*----------------------------------------------------------------------------------------------*/        


  in kubernetes context 

  container is deployed within a pod 
    conatainer : is an running instance of an image. 
    image:  In the context of containerization, an image is a lightweight, standalone, and executable software package that contains everything needed to run a piece of software, including the code, runtime, libraries, environment variables, and configuration files. 


   /*
     minikube start; 
     minikube start --profile=myCluster;                   // creating cluster with givenName

     kubectl create deployment my-app-name --image=link; 
                // link is the link of registory where the image is, by default it is picked from docker hub.
     kubectl create deployment my-nginx --image=nginx:latest; 

                      
            // creates a pod with container = running nginx image.  since image is not found on local docker will pull it from docker hub
            // name of deployment/container is my-nginx

     kubectl get deployments;              // see the status of all deployment 
     kubectl get pods;                     // see the status of all pods
     kubectl delete deployment my-nginx;   // delete the deployment my-nginx

   */ 

      // internet > cluster > server -- pod > container               
   - now our container is running inside a pod.
   - nginx application inside the container is listing at 80 port      // port 80 is default for nginx.

    to access the application we have service-object similar to port binding in case of docker.

    /*
      kubectl expose deployment my-nginx --port=80 --type=LoadBalancer; 

        // The kubectl expose command is used in Kubernetes to create a Service object that exposes a deployment, replication controller, or pod to the outside world. 
        // we are using it to expose a deployment named "my-nginx" listening on port 80 and the type LoadBalancer


      minikube service my-nginx; 
        // 
                |-----------|----------|-------------|---------------------------|
                | NAMESPACE |   NAME   | TARGET PORT |            URL            |
                |-----------|----------|-------------|---------------------------|
                | default   | my-nginx |          80 | http://192.168.49.2:32107 |
                |-----------|----------|-------------|---------------------------|
        - The minikube service command is used to expose a service running in a Minikube cluster. It opens a web browser to a service or displays information about the service.
        - we need to have Minikube installed and running for this command to work. Additionally, the "my-nginx" deployment must be running and accessible within the Minikube cluster for the command to succeed.

      kubectl get services;       // list the services / service objects in kubernetes cluster. 
    
    */


%%%% TODO : learn how to create docker image of an application & push it to remote repo. %%% 
 

/*-----------------------------------------------------------------------------------------------------------------*/    
/*-----------------------------------------------------------------------------------------------------------------*/    
/*-----------------------------------------------------------------------------------------------------------------*/    




    /*  To see the logs of running image inside the pod

        Kubectl logs pod_name;              // name of pod which we see in kubectl get pods;

        kubectl describe pods.              // describes the pods details.
    */



  ROLLING OUT CHANGES : how kubernetes handles change in the application code in production environment.  

    /* CASE : when we need to change the image running 
        source_Code changed --->  new image is created   --->  push this image to remote registry
        
     kubectl set image deployment my-webapp webapp-demo=new_image_link; 
             // container name  <- webapp-demo
             // deployment name  <- my-webapp
             // sets the image ( of new_image_link ) to given container of given deployment  
        
         - in background  
            kubernetes keeps old pod running.                                       : old running
            creates a new pod with with deployment, conatiner/ new image.          :new  creating deployment
            when the new pod gets running .                                       :new  running 
            kubernetes terminates old pod.                                       : old terminating 

         -  conculsion : 0 down time as kubernetes kept the old pod running untill new was Up. 
         - we can access our application using same service oject  ( created with old image ).  

      kubectl rollout status deplyment my-webapp; 
            // deployment name <- my-webapp

    */
 ROLL BACK CHANGES : 
    /*  CASE : we need to revert 
        CASE : when image is not found on registry 

          kubernetes keeps old pod running.                                              : old running
          trys creates a new pod with with deployment, conatiner/ new image. & fails     : new  imagePullBackoff

          rollout status of deployment will be stuck to "waiting for rollout to finish", as image is not on registry 

        $kubectl rollout undo deployment my-webapp; 
    */

when our application stops running in pod due to any reason 
    - kubernetes restarts the pod.    
    - now untill the pod is in running state ----> there will be down time, (the apllication is down).
        solN: keep multiple instating of application running,     // scaling 
    - when we get pods status we can see the number of times application has restarted. 

    /* SCALE : increase or decrease pods.
        kubectl scale deployment my-webapp --replicas=4; 
    */
        - now instead of 1 pod 4 pods will be created with the same image as in my-webapp deployment
        - i.e our application is running in 4 pods. 
        - if 1,2 ,3 is down our application will still be up. 


/*--------------------------------------------------------------------------------------------*/
/*-------------------------  Using config file for deployment & service ----------------------*/
/*--------------------------------------------------------------------------------------------*/

%%%% TODO : learn to create deployment & service config file %%% 

 /*
    $kubectl apply -f   path_to_dir/my-webapp-deployment.yml; 
           // path_to_dir  --> where deploymen file is 
           // my-webapp-deployment.yml --> deployment config file

    $kubectl apply -f   path_to_dir/my-webapp-service.yml;   
           // my-webapp-service.yml --> service config file
    
        $minkube service service_name;            // exposing service running in minikube ckuster.          
            
 */


/*--------------------------------------------------------------------------------------------------*/
/*---------------------   running multiple containers using kubernetes--------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/


MULTIPLE CONTAINER in SAME Pod

     case : deploying 1 monogoDB container  && 1 NodeJs continer  in same pod.  

       features:
        - communication b/w mongoDB & nodeJs app is done by local host as they are in same pod. 



       drawbacks : 
        - suppose there are 3 pods for load balancing --->  each time data will be saved/ retrieved from diffent DB, as request can go to any pod. 


MULTIPLE CONTAINER each in DIFFERENT POD. 

        features: 

        how will NodeJs app communicate with mongoDB
         - ip : service-name         // service name of mongo-DB container service. 
         - port : mongoDB           // port exposed by kubernetes/minikube in our case for accessing mongoDB service  

         we can pick these values from environment variable. 
