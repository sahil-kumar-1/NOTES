terminal : programme that runs shell. 

shell : ( called bash on ubuntu), 
        takes our command and gives to OS  for execution
        called shell as its a outer layer of OS.

relative path  :     xyxz/abc/...            path from current working directory

absolute path  :     /home/fa065034/...               path from / directory highest directory
                    ~/Pictures                        path from user home directory  i.e from fa065034/


shell expansion :   shell performs some operations on given commands which determines how they are interpreted.  


$ ctr + r         // to search for previous typed commands (reverse search )


$ whoami          // to know the user name logged  in as 

$ man command_name       // to get the manual of that command  

        eg: man cd  

        to quit manual page    : q
        to scroll 1 page       : space 


$ clear           // clears the terminal screen

        ctrl + l : does the same job
        clear + x : clears the screen but not removes the history.


$ pwd             // prints current working directory

$ ls              // lists the content of current directory

        ls path           : to list the content of directory whose path is given  (here path is relative i.e from current folder )
        ls /home/....     : we can also give absolute path ( path from home or root directory) 

        ls -l   : get a long listing format ( more informative )
        ls -a   : show .file (hidden ones) too                       // ls -al comb of both -l and -a 
        ls -A   : show . and .. files too 

$ du                            // to see the file or folder size 
        du -h  file_name 
        du -sh folder_name     
        du dir_name              // outputs size of the directory
                                // -m for size in mb , -g for size in gb , -h for human readable size

                du -h | sort -h                // -h in sort is for considering the prefix while sorting 


$ cd dir_path               //  changes the working directory to directory whose path is provided

        cd ..        // go back to parent folder
        cd -         // go to prev working dorectory
        cd ~         // go to user home folder              home/fa065034/
        cd /         // root directory


 		
$ mkdir         
 
 	        mkdir -p temp2/temp3                   // make  "temp2 > temp3" in curr         // making sub directories       ( make parent directory as needed )
 	        mkdir temp1                            // makes curr > temp1                   // make sure no prev dir exists with same name
 	        mkdir temp4/help                            // makes help in "curr > temp4"                 // make sure no prev dir exists with same name
                mkdir t1 t2 t3                         // making 3 folder in  pwd. 


$ rmdir  folder_name                                    // deletes empty folder ( we can delete multiple empty folder at once too : $ rmdir  x y z)


$ touch 
 
 		touch hello.txt                        // creating new file     ( hello.txt and hello.pdf are diff files)
                                                       // updates the time stamp if the file already exixts
                touch aplles balls pen                 // creating multiple files at same time   

                touch app.{js,html,css}                 // create app.js app.html app.css

                touch {app,log,map}.js                  // create app.js log.js map.js

 
$ rm                                   // deleting files and folders
            /* files deleted from terminal are completely gone  <-- not to bin      */       

                rm path/file.extention               // NOte path is always relative to current directory             // delete file

                rm balls pen           // deleting one or multiple files       

                rm -v apples           // -v suffix after command is verbose  ->> it tells what command did after execution of the command
                
                rm -r dir_name         //  delete an empty directory 
                                       //  -r : recursively apply same operations  ->> delete all inside files/folders recursively
		
                rm -rf path/dir_with_content_to_remove/                                        // delete folder having some file
                
                rm -ri dir_name        //  -i : interactive   ->> asks before preforming every action 

                rm *.txt               // delete anything.txt      similarly rm *.?? :     // ? is some character


$ open 
                open .            // to open pwd in file manager

                open hello.txt    // to open the file in default application

                open path/file.ext                     // we can also use "xdg-open" command 



$ mv            
                mv p1/f1.e1 p2/f2.e2                   // rename file f1.e1 to f2.e2  && move it from p1 to p2 (path2)
                mv p1/f1.e1 p2                         // move f1.e1 from p1 to p2
                mv f1.e1 f2.e2                         // rename the file only

                mv temp1/a b c temp2/                  // moving multiple files at a time  //   moving  a b c from folder temp1 to temp2     

                mv p1/dir1 p2/dir2                     // moving directoy to another one       // mv does not need -r suffix


$ cp 
                cp p1/f1 p2/f2                         // copy f1 from path1 to path2 as f2
                cp f1 f2                               // copy in same folder
                cp p1/f1 p2                            // copy to diff folder with same file name

                cp -r p1/dir1 p2/dir2                  // copy folder dir1 as dir2 to a new location (p2) from p1


$ head 
                head demo.txt                           // output 1st 10 lines of the file
                head demo.txt -n 100                    // first 100 lines of the file


$ tail         
               tail demo.txt
               tail demo.txt -n 100 

               tail -f demo.txt                      // print last 10 lines and print new items if added ( usefull in case of log files )


$ command > file.ext                                 // > replaces the file content with output of command

                pwd > temp1/a.txt                    // currrent directory path will replace the content of a.txt intead of printing the path on terminal

$ command >> file.ext                                // same as > but appends the result in the file instead of replacing the content of the file
                                                     // if the file does not exists it will be created.


$ cat
                cat a.txt                             // gives entire content of file (a.txt) on terminal                
                cat a.txt b.txt                       
                
                cat -n a.txt                             // ------------------------------------------------ with line numbers             

                cat a.txt b.txt c.txt > concat.txt    // concatinating multiple files <<- redirect the content of a then b then c to concat.txt


$ less
                less a.txt                // to see the content of file in less editor  -> we can explore from top 
                   
                     down/up key     // to move a line down / up
                     space           // scroll a page down
                     b               // scroll a page up
                     g               // takes to start of the file
                     shift+g         // takes to bottom of the file

                     /key            // to search     ( at cursor at bottom )
                     exit            // to exit 
                     q               // to quit or exit


$ echo
                echo "hii"           // outputs whatever we give to termianl as output
                                     // mainly used with ">" and ">>" command 
         
         /*                 shell expanison     we can use bunch of other commznds with shell expansion like mv, cp, etc             */

                echo *.txt           // anything that ends with .txt
                echo *.???           // any_thing.anything_of_3_char
                echo $JAVA_HOME      // to see the set java path          ( here java_home is our environment variable name which is expanded to path specified )

                echo day{1..365}     // day1 day2 .... day365

$ source path/file         // to execute the file immidiately ( config files like .bashrc )                

$ wc             
                wc a.txt             // counts lines words bytes in the file 


$ command1 | command2                       /*    piping : using output of one command as input to other command     */ 

                ls -a | wc -l          //  input to wc "list all files/folder names in pwd " 
                                       //  output of wc "count of lines ->> number of files folders in pwd"


$ sort
                sort a.txt             // ouputs the content of file a.txt in sorted mannar  ->> original content of file does not change 

                sort -n num.txt        // to sort numbers , without -n sorting will be on string i.e lexicographically                                         
                                        
                                       // -r for reverse order
                                       // -u for unique values / elements


$ unique 
                unique a.txt           // outputs the file content after removing adjacent duplicate values.

                unique -d a.txt        // only print the adjacent duplicates

                unique -c a.txt        // count the adjacent duplicates

                     eg: sort a.txt | count -c | sort -nr 

                     

$ diff a.txt b.txt          // shows the difference between content of both the files.                     


$ find 
                find . -name 'app'      // -name : find by name       ( both files and folders will be searched) (does not searches inside any file)
                                        // . means find in current folder and its nested structure. 
                                        // 'app' will be searchead for a complete map                  try '*app' : ending with app , '*app*' containing app

                find path -iname 'exp'  // -iname for case insensitive search
                
                find . -type d -iname '*log*'    // -type to search by type // d for directory  // f for files

                find . -name '*e' or '*f'        

                find . -type f +100k              // select files > 100kb

                find . -type f -exec cat {} \;            // execute cat command on selected files // can execute any valid command // {} is filled with file names at time of execution // \; is for termination
                find . -type f +100k -exec ls -l {} \;


$ grep                                                      //global regular expression print                

                grep green demo.txt                         // find all occurance of green in demo.txt

                grep green -nC 2 demo.txt                    // shows two lines after and before for every green in demo.txt

                grep -r "chicken"                             // search recursively in all files in the current directory for "chicken"

                grep -rE -o "reg-exp"                         // to find particular patterns like emails etc: // reg-exp = regular expression





$ df                      // outputs the capacity and how much using of a drive.        //  
                df -h


$ history            // to see history of all the commands we have run
                     // every command when being executed is allocated a number   
                     // we can use !that_num to run the command 

                history | less                 // to open the output of the Hisotry in less editor. 
                history | grep "cookies"       // to find command executed in past having cookies in it.



$ ps 
                ps           // returns list of all process created by current user. // process status.

                ps -ax        // all process started by anyone.   // ps -axww  : to get wrap over result

                ps -axww | grep "Visual Studio Code"        // to check processes started by vs code

$ lsof         
                lsof -t -i:8070    // lists the process running on port (8080)


$ top                              // shows top cpu extensive processes

                top -o mem        // short a/t what amount of mem it taking out;



$ kill    
                kill -l           // -l : lists all the signals we can send ( progrm source code handles these sigals which we intent to kill)

                kill p_id          // GENTLE    way that gives time to save the files and other stuff and then close the process. 

                kill -9 p_id         // forcefully kill the process. 

                killall p_name       // kill all the instance of process whose name is provided        
                                    // we can use signals too like -9 



      /*          jobs , bg , fg  these commands work together     
      
      ctrl+z  == ^z      pauses / suspends the current job 
      
        */

$ jobs                   // shows the suspended jobs/process or jobs running in background. 

$ fg 1                    // to resume job 1 in foreground  // we can use fg or bg if there is only 1 job

$ bg 1                    // to resume job 1 in background

$ sleep 10 &              // sleep for 10sec , & specifies run the process in background. 


        /*            zipping unzipping files        */

$ gzip 
                gzip demo.pdf         // compresses the file // zip replaces the original file

                gzip -c demo.pdf > demo.gz    // both zip and file will remain
                gzip -k demo.pdf            // does the same job
                                         // the  level of compression (1 to 9)   // 1 less time less compressed  // 9 more time better compressed // 6 is default value.

                gzip -k a.pdf b.txt     // gzip zips only 1 file i.e can not club many file in 1 zip  // here a.gz, b.gz will be created

                gzip -d demo1.gz         // for unzipping the file. 



$ gunzip demo1.gz                        // does same job as gzip -d  


$ tar
                tar -cf target.tar a.pdf b.txt c.xml              // creates file target.tar archived version of all 3 files. 

                tar -xf target.tar                                 // unArchiving tar in pwd
                tar -tf target.tar                                 // to see the fies in the tar 
                
                tar -xf target.tar -C directory                     // unArchiving tar in pwd > directory

                gzip target.tar                                 // creates target.tar.gz  // method of zipping multiple files 

                tar -czf target.tar.gz a.pdf b.txt c.xml        // creating a zipped file of archive of all 3 files.
                                                                // tar -xf will unzipp and unarchive the  .tar.gz file


$ nano demo.txt                                  // nano is an text editor easy but less powerfull than vim editor.
                                               // if file is not present nano will create it. 


$ alias 
                alias ls="ls --color=auto"               // till the terminal session continues ->> to invoke  "ls --color=auto" we can use ls. // will not work on other terminal or when pc restarts.
                                                        // so to permanently store these alias ->> store in .bashrc file ->> every time the shell loads up it runs .bashrc file  (  find comment some more alias )
                                                        // source .bashrc  : to run it now ( instead loading a new terminal / shell )
                                                        
                unalias ls                               // to remove the binding done to ls ->> ls will work as usual

                /*  alias ls = "ls $pwd"       //  $states the variable // value of $pwd will be set in stone with current pwd. 
                    alias ls = 'ls $pwd'       // value of $pwd will be resolved each time ls runs. 
                */

 | xargs    

                /*
                        $sort players.txt                 // giving the content of file to sort as argument 
                        $ls | sort                       // output of ls is provided to sort as standard input.

                        but there are limited commands which work on std input  (eg : touch, rm, ls ): so the use of pipe command is limited  ->> here xargs comes to play.
                */

                $ find . -size +10M | xargs ls -l        // xargs passes the name of files > 10mb to ls -l as parameter 


$ln
                ln     path2/myBackEnd.jar  path1/application.jar            // creates a hard link  ( now application.jar points_to / is hard link of myBackEnd.jar)
                ln -s  path/link_file   path1/f1                             // for creating soft link.

$link              // creates link to files ( similar to shorcuts but its not a copy of original instead it points to same)
                   // NOTE : ln is standard linux command link is not standard linux command.
                
                link demo.txt hardLink.txt               // now hardLink.txt points to demo.txt     // we delete harLink or original content will still be there in other // if we update by help of one we can see the change when we open the file by other one. 
                link -s demo.txt softLink.txt            // soft link // if original is deleted softLink is of no use. 

                 
$unlink         
                unlink  path/link_file                   // unlinks but keeps both the original & link file.         


                /*   next couple of commands are related to users and permissions   */

$ who                      // tells the users currently logged in  // as many user can work simultaneusly on a system // 

$ su user_name             // to switch user  ( may ask for password )

                su - user_name          // switch user + takes to that users directory. 


$ sudo                  /*    super user do , used to run command as root user ( user need to have permission & his password )
                                in ubuntu you can not login as root user ->> so the users can use sudo for executing commands as root user 
                                where sudo can be used
                                        installing a s/w
                                        editing a file of root user ( as there is no way to login as root user ) 
                                        etc
                                administrator user (in settings) can use sudo command. 
                        
                                for eg: sudo nanp etc/hosts        : editing the system configurations 
                        */


$ password      
                passwd         // to change current user password

                sudo passwd diff_user     // to change some other user password  ( need to have administrators rights )


$ sudo chown                  // change owner // sudo as  we need adminstrators permission for changing owner of file / folder. 

                sudo chown sahil2 music/        // changes the owner from current user to sahil2  ( owner of nested directories are not changed )
                sudo chmod -R sahil2 music/     // changes the owner of nested directories too. 

                sudo chmod sahil2:group_2 music/         // change the owner and group owner       // many users can be part of a group.


                /*   information about file details shown by ls -l

                -rw-rw-r-- 1 fa065034 fa065034    0 Feb  2 16:27 hhhh.txt         // 
                drwxrwxr-x 2 fa065034 fa065034 4096 Jan 30 22:20 x.pdf


                - : file ,    d : directory  , l : link
                rw-rw-r--    permission for owner , group owner , other users            // rwx //  r: read w: write x: exicute   // - in place represent that operation can not be performed 

                chmod command  ( change mode ) is used to alter these permissions.

                */

$ chmod 
                /*  1st ( u,g,o,a) = (user, group, other, all)  : who we are changing permissions for.
                    + add the permission , - remove the permission
                */                

                chmod a+w demo.txt           // add write perssion for all users.
                chmod og+r                   // giving read permission to owner and group.

                chmod 755 demo.txt           // octal notations  // 7 = 111 = rwx for owner  // 5 = 101 = r-x for group  // 5 = 101 = r-x for other 

                chmod g = rw                 // setting group permission to rw- // diff combinations can be used 


$ which 
                which vim                    // used to locate the executable file associated with the given command by searching it in the path environment variable.
                which java


$ locate                                     // The locate command finds files in Linux using the file name / file name along with some path. 
                locate java     
                which java | xargs locate




               working with server 



$ free 

                 free -h         // to see the staus of memory|ram on server in human readable form. 


$ scp             // Secure Copy Protocol                       

               scp ./data-news-services-0.0.1.jar developer@192.168.226.11:/data/uba/apps/          //  uploading/copying file to server     // user name : "developer@192.168.226.11" , folder path in server "/data/uba/apps/"
               scp developer@192.168.226.11:/home/developer/sahil/data_news_dump_1.sql ~/Downloads  // copying file from server to local pc  //                                                                               // from inside the folder where the file is 

$ supervisorctl             // manage the services existing. 
 
               sudo supervisorctl status all                     // to see the status of all services
               sudo supervisorctl restart data-news-services     // to restart the service data-news-service

     
$ ping 
                                          // ping is the primary TCP/IP command used to troubleshoot connectivity, reachability, and name resolution
               ping 192.168.226.11        // returns the details of connection 1 req & respose from server 

$ ./demo.sh.                              // to run a .sh config file               