Q : what is supervisor ? 
-> process management tool which helps in manging processes. 


Q: difference in supervisord & supervisorctl ? 
-> 

Q: what is supervisor.conf file  where are they located ?
->  all supervisor confugaration can be written in 
            1. append the confugaration for your program in supervisord.conf file
            2. write a separate new_super.conf file and save it in conf.d/ directory.

    both the supervisord.conf && conf.d/ directory are located in etc/supervisor  directory. 


Q: how to write a basic supervisor.conf file ? 


Q: basic supervisorctl commands ? 
-> 

        sudo supervisorctl read        // reads all the file in config.d/ directory & supervisor.conf file. 
        sudo supervisorctl update      // reads all the file in config.d/ directory & supervisor.conf file & start any newly introduced programs. 
        sudo supervisorctl status all  // shows the status of all programs managed by the supervisor. 


Q: numprocess propery in .conf file ? 
-> 

        In the context of Supervisor, the "number of processes" (often specified using the numprocs property in the Supervisor configuration) refers to how many instances of a program or service Supervisor should manage concurrently.

        Here's a more detailed explanation:

        Single Process (Default):

        If you do not specify the numprocs property in your Supervisor configuration, Supervisor will assume a default value of 1.
        In this case, Supervisor will manage a single instance of the program specified in your configuration.
        Multiple Processes:

        If you specify numprocs with a value greater than 1 in your Supervisor configuration, Supervisor will manage multiple instances of the program.
        For example, if you set numprocs to 3, Supervisor will manage and control three separate instances of the program, each running concurrently.
        The primary use case for running multiple processes is to achieve parallelism or redundancy. For instance, in the case of a web server or application, you might want to run multiple instances to handle incoming requests simultaneously, distributing the load and ensuring high availability. Each instance runs independently but can be controlled collectively by Supervisor.

        When you start or stop the program using Supervisor commands, such as sudo supervisorctl start myapp or sudo supervisorctl stop myapp, these commands will affect all the instances specified by the numprocs value. It allows you to manage multiple instances of the same program as a group.


Q: redirect_stderr property in .conf file ?
->      redirect_stderr=true is used to specify that stderr should be redirected to the same location as stdout.
