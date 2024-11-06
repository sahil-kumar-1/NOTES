

 prerequisits

    1. java 

        sudo apt update
        sudo apt install openjdk-11-jdk

    2. kafka

        wget https://downloads.apache.org/kafka/3.4.0/kafka_2.13-3.4.0.tgz        // official website.
        tar -xzf kafka_2.13-3.4.0.tgz
        cd kafka_2.13-3.4.0



 Start the ZooKeeper Server

   
        ./gradlew jar -PscalaVersion=2.13.12
    /* 
       if the Kafka distribution you downloaded requires you to build the project first. 

            - ./gradlew jar -PscalaVersion=2.13.12 :
            
                    ./gradlew is the Gradle wrapper script included with Kafka.
                    jar is the task to build the JAR files.
                    -PscalaVersion=2.13.12 specifies the version of Scala to use. Ensure that the version you specify matches the version of Kafka you downloaded.
    */

        bin/zookeeper-server-start.sh config/zookeeper.properties
  /*
        - Kafka uses ZooKeeper to manage distributed configurations. Start ZooKeeper using the configuration file provided with Kafka:
        

        - bin/zookeeper-server-start.sh : This is the script to start the ZooKeeper server. It's an executable script provided by Kafka for starting ZooKeeper.

        - config/zookeeper.properties This is the configuration file for ZooKeeper. It contains settings and parameters that ZooKeeper uses to start and run.
   */



 Start the Kafka server 

        bin/kafka-server-start.sh config/server.properties
    /*
        - The script reads the server.properties file specified as an argument. This file contains key-value pairs of configuration settings that control various aspects of the Kafka broker's behavior.
        
        bin/: This directory contains executable scripts and binaries for Kafka.
        kafka-server-start.sh: This is the script that starts a Kafka broker. It sets up the necessary environment and invokes the Kafka server with the specified configuration.

        config/: This directory contains configuration files for Kafka.
        server.properties: This is the configuration file for the Kafka broker. It includes various settings and parameters that define how the broker should operate.
    */


 Basic kafka operations.

    1. Creating new topic

        bin/kafka-topics.sh --create --topic test --bootstrap-server localhost:9092 --partitions 1 --replication-factor 1

        /*
            kafka-topics.sh: This script is used to manage Kafka topics. It can create, list, describe, and delete topics.

            --create : This flag tells the kafka-topics.sh script that you want to create a new topic

            --topic: This flag specifies the name of the topic.

            --bootstrap-server: This flag specifies the Kafka broker(s) to connect to.  ( ocalhost:9092: This indicates that the Kafka broker is running on localhost (the local machine) and listening on port 9092.)
        
        */

    2. Consuming from topic 

        bin/kafka-console-producer.sh --topic test --bootstrap-server localhost:9092


    3. Pushing to topic

        bin/kafka-console-consumer.sh --topic test --bootstrap-server localhost:9092 --from-beginning


