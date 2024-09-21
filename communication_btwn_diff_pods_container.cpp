/*------------------------- CREATING DEPLOYMENT ------------------------*/


kind : deployment
       // deployment | service |  

metadata: 
    name : nginx-deployment
        // name of resource
    labels :  
        // The metadata.labels section under metadata defines labels for the  resource itself.   ( deployment resource etc )
        // These labels are used to identify and organize the Deployment within the Kubernetes cluster.
        app: nginx
        environment: production
        tier: frontend

spec : 
     // Specifies the desired state for the Deployment.
    replicas : 3
        //  is used to denote the number of identical instances of a pod or set of pods managed by a controller, such as a Deployment or a ReplicaSet.       
    selector:
        //selector  Defines how Kubernetes identifies which pods are managed by this Deployment.
        matchLabels:
            // matchables Specifies that pods with labels matching the specified criteria are considered part of this Deployment
            app: nginx
            environment: production

template:
    //template Defines the pod template used by the Deployment to create new pods.
    metadata:
        // metadata Contains metadata for the pods created from this template.
        labels:
            //  Labels applied to the pods created from this template. It's also set to "app: nginx".
            app: nginx
            environment: production
spec:
    // Specifies the specification for the pods created from this template.
    containers:
      // Specifies the containers to run in the pods.
    - name: nginx
      image: nginx:1.14.2
      ports:
        // POrts This field specifies the list of ports to expose from the container. ( denoted by containerPort )
        // If your application inside the container listens on a port but you don't explicitly expose that port in the container configuration within Kubernetes, then the application will still be able to listen on that port inside the container, but it won't be accessible from outside the container.
      - containerPort: 80            
      - containerPort: 8070




Q: how matchLabel works ? 
    When specifying a label selector in Kubernetes, the labels provided in the selector are considered as a set of requirements, and any pod with labels matching those requirements will be selected.

    For example, if your pod has two labels, let`s say app: frontend and env: production, and your Deployment`s selector is defined as matchLabels: app: frontend, then any pod with the label app: frontend will match the selector, regardless of whether it also has the env: production label or not.

    However, if your Deployment`s selector is defined as matchLabels: app: frontend, env: production, then only pods with both labels app: frontend and env: production will match the selector.

/*--------------------------------------------------------------------------------------------------------------*/



In the context of Kubernetes, a "resource" typically refers to any entity that Kubernetes can manage and manipulate. This includes things like pods, services, deployments, replicasets, configmaps, and more.

/*--------------------------------------------------------------------------------------------------------------*/

MULTIPLE CONTAINER each in DIFFERENT POD. 


    case : deploying 1 monogoDB container  && 1 NodeJs continer  in 2 diff pod.  

        features: 

        how will NodeJs app communicate with mongoDB
         - ip : service-name         // service name of mongo-DB container service. 
         - port : mongoDB           // port exposed by kubernetes/minikube in our case for accessing mongoDB service  

         we can pick these values from environment variable. 

      /*  mongoDB deployment & service config

                apiVersion: apps/v1
                kind: Deployment
                metadata:
                    name: mongo-app
                spec:
                    replicas: 1
                    selector:
                        matchLabels:
                            app: mongo-app
                template:
                    metadata:
                        labels:
                            app: mongo-app
                    spec:
                    containers:
                    - name: mongo-app
                        image: mongo:latest

                ---

                apiVersion: v1
                kind: Service
                metadata:
                name: service-mongodb
                spec:
                selector:
                    app: mongo-app
                ports:
                    - name: tcp
                    port: 27017
                    targetPort: 27017
                    
      
      */   

      - instead of wrting deplyment & service config in different file we write them in same file separated by "---"

      /* config mapping file 

                apiVersion: v1
                kind: ConfigMap
                metadata:
                    name: mongo-config
                data:
                    MONGO_HOST: "service-mongodb"
                    MONGO_PORT: "27017"      
      */

      /* NodeJs deployment & config file

                apiVersion: apps/v1
                kind: Deployment
                metadata:
                name: node-app
                spec:
                replicas: 2
                selector:
                    matchLabels:
                    app: node-app
                template:
                    metadata:
                    labels:
                        app: node-app
                    spec:
                    containers:
                    - name: node-app
                        image: philippaul/node-mongo-db:04
                        env:
                        - name: MONGO_HOST
                            valueFrom:
                            configMapKeyRef:
                                name: mongo-config
                                key: MONGO_HOST
                        - name: MONGO_PORT
                            valueFrom:
                            configMapKeyRef:
                                name: mongo-config
                                key: MONGO_PORT


                ---

                apiVersion: v1              
                kind: Service
                metadata:
                  name: service-node-app
                spec:
                  ports:
                    - name: http
                      port: 8080
                      targetPort: 3000
                selector:
                    app: node-app
                type: LoadBalancer      
      */

     // service resource 
       - apiVersion: v1       // version of the Kubernetes API being used
       - kind:Service         //  Specifies the type of Kubernetes resource being defined. Here, it's a Service, which is used to expose a set of pods as a network service.
        metadata:             // meta data about the service
            name: service-node-app        // name of service.
        spec:                 // specification for the service
           ports:             // ports that service should expose
            - name: http      // 
              port: 8080       // Specifies the port number on which the service should listen. ( port exposed to k8 cluster - external hits on pods )
              targetPort: 3000 // port on the pods to which the traffic should be forwarded  ( port inside the pod on which the service is running )
        selector:              // Specifies the labels that should match the labels of the pods to which the service should route traffic. ( app is the label )
            app: node-app      
        type: LoadBalancer     


    //  how is env varibles specified inside the pods. 
        env: 
         - name : abc
           valueFrom:
              configMapKeyRef:
                - name : xyz
                - value : X_Y_Z

       -  name abc    : name of the environment variable within the container.
       -  valueFrom configMapKeyRef : abc env variable will be resolved in some configMap file. 
       -  name xyz    : name of the config map file.
       -  value X_Y_Z : key/property in the config map file xyz whose value will be assigned to env varible.