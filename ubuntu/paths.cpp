
/usr/lib/jvm/java-17-oracle/bin/java             // for java 17 in my pc

/etc/hosts                   // file which stores mapping of host name to ip address in local computer. 
    // sudo gedit /etc/hosts    ->> to open the file in gedit editor as admin 

// setting java path in ~/.bashrc
export JAVA_HOME=/usr/lib/jvm/java-8-o.m2 folder is typically not directly related to the project itself, but rather to the local Maven repository used by Maven (the build tool) to store and manage dependencies (libraries) required by your project.penjdk-amd64/jre
export PATH=$JAVA_HOME/bin:$PATH                             // final PATH should point to an executable 


~/.m2   // home directory of user contains a .m2 folder where all the spring boot projects are 
-> .m2 folder is typically not directly related to the project itself, but rather to the local Maven repository used by Maven (the build tool) to store and manage dependencies (libraries) required by your project. 