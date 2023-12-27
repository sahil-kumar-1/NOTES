
->  Bash script is a computer program written in the Bash programming language.

-> bash script file
        - extension   .sh   // custom_scripts.sh
        - Each Bash based Linux script starts by the line-
                    #! /bin/bash                               // #! is referred to as the shebang and rest of the line is the path to the interpreter specifying the location of bash shell in our operating system.

        -  # is used for line comment.
        -  echo is used to print the output on terminal             
        -  path_to_bash_script_file/fileName.sh                // to run script file on terminal.


-> #!                  // shebang

    when a script with a shebang runs as a program, the program loader parses the rest of the lines with the first line as an interpreter directive. So, SheBang denotes an interpreter to execute the script lines, and it is known as the path directive for the execution of different kinds of Scripts like Bash, Python, etc.

    - It should always be on the very first line of the Script.
    - There should not be any space before the hash (#), between the hash exclamation marks (#!), and the path to the interpreter.

NOTE: the bash script file to be executed must be having execute permission. 


-> BASH comments 

        single line :    #
        multiple line :  <<COMMENTS  multi_line_comment COMMENTS   or  : ' multi_line_comment '

-> QUOTES in bash

        String : no differences either we use a single quote or double quote for String.
        /*
                name1 = 'hello world'
                name2 = "hello world" 
                echo $name1              // hello world
                echo $name2              // hello world
        */        

        NOTE : shell variable expansion will only work with double-quotes.
               If you define any variable in single quotes, then it will not be considered as a variable
        /*
                eg : 

                name="hello world"
                echo "$name how are you"                         // hello world how are you
                echo '$name how are you'                         // $name how are you
        */

/*---------------------------------------------------------------------------------------------------------------------------------------------*/


-> VARIBALES in bash

        : variable name can include alphabets, digits, and underscore, and its name can be started with alphabets and underscore only.

        - Prefix the variable name with dollar ($) sign while reading or printing a variable.
        - Leave off the dollar sign ($) while setting a variable with any value.
        - variable names are case sensitive.
        - There should not be whitespace on either side of the equal sign (=) between the variable name and its value.
        - bash varibles are untyped

        - There is no need of using any quotes, either single or double, to define a variable with single word without white space. 
          To input multiple words or String as a single item in a variable (i.e containing space ), then make use of quotes for enclosing your content in that variable.
                Single Quote ('') helps to treat every character.
                Double Quote ("") helps to do the substitution.
        /*
                path=/com/java/example
                echo $path

        */

        - commands related to system variable.
                set : 
                        set command without any arguments is used to display all shell variables and functions.
                        it show both environment variables and variables specific to the current shell session.

                printenv :
                                printenv command is used to display the values of environment variables.
                                // printenv        -> all environment variables are printed with their values.
                                // printenv PATH   -> prints the value of PATH bash variable.

                env : lists all the environment variable.                                         

-> VARIBALES : BASH_SCRIPT arguments                 // ./customRunSript.sh cm local

        In a Bash Shell, they are used with the reference of the following default-parameters or the special variables.

                $0 specifies the name of the script to be invoked.
                $1-$9 stores the names of the first 9 arguments or can be used as the arguments` positions.
                $# specifies the total number (count) of arguments passed to the script.
                $* stores all the command line arguments by joining them together.
                $@ stores the list of arguments as an array.
                $? specifies the process ID of the current script.
                $$ specifies the exit status of the last command or the most recent execution process.
                $! shows ID of the last background job.

        ways to pass command line argument in a script file.

                // ./customScript.sh monday september 2023

        1. using positional number
                // month=$1;              // september

        2. using Array      
                /*
                   arr=("$@")
                   year=${arr[2]}         // 2023
                */


-> VARIBALES : command substitution 

        - command substitution is done by two ways

                1. using ``   //  x=`cd ~/Download; pwd`

                2. using $()  //  x=$(cd ~/Download; pwd)

                // echo $x              -- result : /home/fa065034/Downloads

          > linux executes the command inside `` or $() in a sub terminal and stores the output in the variable.
          > NOTE : the multiple line output returned by substitution is in single line i.e without trailing or leading spaces. 
          > we can treat the variable like a normal shell script variable.



/*---------------------------------------------------------------------------------------------------------------------------------------------*/

-> READ : reading user input from terminal in a bash script file.

            1. Storing terminal input of read command in a varibale.
                /*
                    script : 

                       echo "Enter the user name: "  
                       read first_name
                       echo "user name is : $first_name" 

                    Terminal
                        Enter the user name:
                        sahil
                        user name is : sahil

                Note on terminal we get the cursor to enter name on next line of echo output.
                
                */


              2. what if no variable is passed along with read command in script ?
              -> read command stores the input from terminal into biuld in variable REPLY

                 /*
                     script 

                       echo "Enter the user name: "  
                       read 
                       echo "user name is : $REPLY"
                 */


              3. -p  : taking input in same line as promt describing what to enter.
                 -s  : taking input in silent mode i.e input will be hidden while typing  

                 /*
                     script 

                        read -p "username : " user_var
                        echo $user_var

                     terminal  

                        username : sahil
                        sahil


                     Script  

                        read -sp "username : " user_var
                        echo " username : $user_var"  

                     terminal  

                        username : username : sahil

                   NOTE :  when used -s " i.e when input is silent " next echo output will be on same line on which silent input is taken
                           so, echo an empty line before any echo to print the desired output in new line.

                     Script  

                        read -sp "username : " user_var
                        echo ""
                        echo " username : $user_var" 

                     terminal  

                        username : 
                        username : sahil


                 */   

               4. -a :storing input in a array.
                  /*
                      script

                        echo "enter names"
                        read -a var
                        echo "names are ${var[0]}, ${var[1]}, ${var[2]} "

                      terminal

                        enter names
                        hello dear sahil
                        names are hello, dear, sahil  
                           
                  */   


/*---------------------------------------------------------------------------------------------------------------------------------------------*/



-> date

        Format Option
        with Codes	Part of Date	Description	                                                                        Example Output
        
        date +%a	Weekday	        Name of a weekday in short form (e.g., Sun, Mon, Tue, Wed, Thu, Fri, Sat	           Mon
        date +%A	Weekday	        Name of the weekday in full form (e.g., Sunday, Monday, Tuesday, etc.)	                   Monday
        date +%b	Month	        Name of the month in short form (e.g., Jan, Feb, Mar, etc.)	                           Jan
        date +%B	Month	        Name of the month in full form (e.g., January, February, etc.)	                           January
        date +%d	Day	        Day of the month (e.g., 01)	                                                           27
        date +%D	MM/DD/YY	Current Date; shown in MM/DD/YY	                                                           08/27/2019
        date +%F	YYYY-MM-DD	Date; shown in YYYY-MM-DD	                                                           2019-08-27
        date +%H	Hour	        Hour in 24-hour clock format	                                                           16
        date +%I	Hour	        Hour in 12-hour clock format	                                                           04
        date +%j	Day	        Day of year (e.g., 001 to 366)	                                                           239
        date +%m	Month	        Number of month (01 to 12 where 01 is January)	                                           08
        date +%M	Minutes	        Minutes (00 to 59)	                                                                   55
        date +%S	Seconds	        Seconds (00 to 59)	                                                                   28
        date +%N	Nanoseconds	Nanoseconds (000000000 to 999999999)	                                                   300261496
        date +%T	HH:MM:SS	Time as HH:MM:SS (Hours in 24 Format)	                                                   15:59:10
        date +%u	Day of Week	Day of week (01 to 07 where 01 is Monday)	                                           02
        date +%U	Week	        Displays week number of year where Sunday is the first day of the week (00 to 53)	   35
        date +%Y	Year	        Displays full year (i.e., YYYY)	                                                           2019
        date +%Z	Timezone	Time zone abbreviation (e.g., IST, GMT)	                                                   GMT


        /*   date --help      // to know all the date related attributes.
        
            d=`date +%m-%d-%Y`
            echo "todays date is : $d"
            


            output : 

                todays date is : 12-17-23
        
        */

/*---------------------------------------------------------------------------------------------------------------------------------------------*/


-> Sleep 

        - as it says sleep for given time      
        - i.e pauses the execution of script when encountered.
        - script execution start from where it was paused after sleep time is over     

			suffix 
			
			s - seconds
			m - minutes
			h - hours
			d - days

			NOTE : when no suffix is provided it is considered as second.

        /*
			script or teminal :

				date +"%H:%M:%S"; echo "wait for 9 seconds";  sleep 0m 9s; date +"%H:%M:%S"	

			terminal output :

				17:56:02
				wait for 9 seconds
				17:56:11


        */  

/*---------------------------------------------------------------------------------------------------------------------------------------------*/


-> Arithmatic Operators    //             +  -  /  *   **   %   +=   -=   *=   /=   %=

    

	ways to perform Arithmatic operations.

	1. inside double brackets  (())

        /*
			 x=3; y=12; ((z=x*y)); echo $z;                  // 36
		
		*/

	2. let construction : built-in command of Bash that allows us to perform arithmetic operations.

		/*
			 x=3; y=12; let "z=$((x+y))"; echo $z;           // 15
		*/

	3. `` and expr

	   -  We are required to use spaces between the items of the expression	

	   /*
	   		a=4; b=5; echo "c=`expr $a + $b`";
	   */













