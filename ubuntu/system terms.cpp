	
	LINUX Shell

		-shell is a user interface that allows users to interact with an operating system ( It acts as an intermediary between the user and the operating system, interpreting commands entered by the user and executing them to perform various tasks ) .
		- provides CLI (command line interface)

 
		  Primary functions of a shell include:

				Command Execution: The shell takes the user`s commands as input and executes them, enabling users to perform a wide range of tasks, such as navigating the file system, running programs, and managing processes.

				File Management: The shell provides commands for creating, deleting, moving, copying, and renaming files and directories.

				Process Management: Users can start, stop, and manage processes using the shell. This includes running background processes, managing job control, and monitoring running applications.

				Input/Output Redirection: The shell allows users to redirect input and output of commands, enabling them to read input from files and write output to files or other processes.

				Pipelines: The shell supports the concept of pipelines, where the output of one command is used as input for another command, allowing complex operations to be performed by chaining multiple commands together.

				Scripting: Shells support scripting, which involves writing sequences of commands in a script file that can be executed as a single unit. Shell scripts allow users to automate repetitive tasks and create custom workflows.

		In Linux, shells can be classified into two main categories: login shells and non-login shells. Additionally, shells can also be categorized based on their interactivity, i.e., whether they are interactive or non-interactive. Let`s explore each of these terms:

			Login Shell:
				A login shell is the type of shell that is started when you log in to your Linux system, either locally or remotely. It is responsible for setting up the user environment, loading user-specific configurations, and initializing certain shell-specific settings. When you log in, the login shell reads and executes one or more of the following files, in a specific order:
				/etc/profile: System-wide profile configuration file.
				~/.bash_profile: User-specific Bash profile.
				~/.bash_login: User-specific Bash login file (used if .bash_profile is not present).
				~/.profile: User-specific profile (used if .bash_profile and .bash_login are not present).
			
			Non-Login Shell:
				A non-login shell is a shell that is started after you have logged in to your system, typically when you open a new terminal window or execute a shell command from within the existing session. Non-login shells do not go through the same initial setup process as login shells. They don`t read the login-specific configuration files like /etc/profile and ~/.bash_profile.

			Interactive Shell:
				An interactive shell is a shell that allows direct user interaction, where you can input commands, execute scripts, and receive output interactively. Both login shells and non-login shells can be interactive.

			Non-Interactive Shell:
				A non-interactive shell is a shell that runs without direct user interaction. These shells are often used to execute scripts or perform automated tasks. They read and execute commands from a script or command-line arguments but do not accept input from the user.

			BASH : bash is interactive an and non-interactive shell
					interactive : when we open terminal or CLI and start typing command. 
					non-interactive : Bash reads and executes commands from a script or as command-line arguments without displaying a prompt or expecting user input.

	
	System properties : it include information about the current user, the current version of the Java runtime, and the character used to separate components of a file path name. 
	
	Environment Variables : they store data that`s used by the operating system and other programs.  

				eg: 
				WINDIR : environment variable contains the location of the Windows installation directory. 
					Programs can query the value of this variable to determine where Windows operating system files are located.
					
				HOME : Contains the location of the user`s home directory. Although

		-> to see the value of a system varible use `echo` command. 
				eg: echo $HOME          // home path of user :              /home/fa065034 
				eg: echo $UBA_HOME      // was set in /bashrc file          /home/fa065034/workspace/SpringBoot/news

		A. System-wide variables : 

			in Linux refer to environment variables that are set globally and apply to all users and processes on the system. These variables define the system`s environment and affect the behavior of various programs and utilities.

					Examples of system-wide variables include:

					PATH: A list of directories containing executable programs. It allows users to run commands without specifying the full path to the executable.

					LANG or LC_ALL: Specifies the system`s default language and locale settings, affecting the language used for messages, date formats, etc.

					TMPDIR or TEMP: Defines the directory where temporary files should be stored.

					PS1 or PROMPT_COMMAND: Controls the appearance of the command prompt.

					LD_LIBRARY_PATH: Specifies additional directories to search for shared libraries.

					TZ: Defines the system`s timezone.


			To configure system-wide variables, you need administrative (root) privileges, as these variables affect the entire system. There are multiple ways to set system-wide variables:

			1. /etc/environment file: 
					- This file is used to set system-wide environment variables. 
					- Each line contains a variable assignment in the format VARNAME=value
					- defined environment variables will be available to all users and processes on the system, regardless of whether they are interactive or non-interactive shells.    // imp!!
					- variables will be available to all users and processes, regardless of the shell they are using (e.g., Bash, Zsh, etc.).          // imp!!
					- It is a simple text file where each line represents an environment variable assignment in the format "VARNAME=value"

					- It`s important to note that the /etc/environment file only allows simple variable assignments and does not support complex shell commands, aliases, or scripts. 
					- changes to the /etc/environment file will only take effect for new sessions or processes. Existing sessions or processes will not be affected until they are restarted.

					eg: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
						LANG="en_US.UTF-8"

					typical use : 

						/etc/environment: Variables in /etc/environment are typically used for setting important system-wide environment variables, such as PATH, LANG, or other global configurations required by various applications.


					After editing the file, you need to log out and log back in for the changes to apply.

			2. /etc/profile file: 
					This file contains system-wide environment settings and is executed for all login shells. 
					eg: export MY_VAR="my_value"

			3. /etc/profile.d/  directory 

					- provide additional system-wide configurations for the login shells. 
					- It allows system administrators and package maintainers to add custom shell scripts or environment variables without modifying the main /etc/profile file directly. 
					- This directory is included by the main /etc/profile script, making it a convenient place to add supplementary configurations.

					- When a user logs in, the /etc/profile script is executed, and it automatically sources all executable files with the .sh extension found in the /etc/profile.d/ directory.	

					eg :  there is shell script in custom.sh file inside "/etc/profile.d/" directory	
					      when user logs in /etc/profile is executed  ->>  /etc/profile.d/custom.sh is automatically sourced

					Using the /etc/profile.d/ directory is a clean and modular way to extend system-wide configurations without altering the main configuration files. It also makes it easier to manage custom settings and allows packages or applications to add their specific configurations to the system.	  

			4.  /etc/bash.bashrc  file

					- The /etc/bash.bashrc file is a system-wide configuration file specifically for the Bash shell (Bourne Again SHell) on Unix-based systems, including Linux.      // imp!!
					- It is a counterpart to the user-specific .bashrc file that exists in each user`s home directory. 
					- While the user`s .bashrc file customizes the Bash shell environment for individual users, the /etc/bash.bashrc file allows administrators to set global Bash configurations for all users on the system.		
					- The /etc/bash.bashrc file is sourced (read and executed) by interactive non-login shells.      // imp!!
					- These shells are typically spawned when you open a new terminal window or invoke a new Bash shell from an existing session. 
					- Unlike the user-specific .bashrc file, which is loaded only for the respective user, the /etc/bash.bashrc file applies to all users, as it is sourced by every interactive Bash shell started on the system			

					Here are some typical uses for the /etc/bash.bashrc file:

						1. Setting system-wide environment variables that should be available to all users.

						2. Defining aliases and functions that are commonly used across the system.

								- Aliases are useful for customizing your shell experience, creating shortcuts for frequently used commands, and making complex or lengthy commands easier to remember and use. 
								- However, they are generally limited to simple substitutions and do not support complex scripting or parameters. For more advanced shell customization or scripting needs, shell functions or scripts should be used instead.

						3. Enabling or disabling Bash options and settings globally.

						4. Configuring the Bash prompt for all users.

						5. Customizing shell behavior for interactive non-login shells.

					- After modifying /etc/bash.bashrc, the changes should take effect automatically the next time any user starts a new interactive non-login Bash shell. However, existing sessions will not be affected until the user starts a new shell.

					- It is recommended to make a backup of the /etc/bash.bashrc file before making any changes, and to have administrative privileges to edit the file since it is located in the system-wide /etc directory.	

			Note : /etc folder is outside space allocated to any user.     ( here /etc has no parent folder )	



		B. User-specific variables: 
				
				User-specific variables can be defined in files like .bashrc, .bash_profile, .profile, or .bash_login. These files are located in the user`s home directory and are used to customize the environment for each user when they log in.

				- User-specific variables in Linux refer to environment variables that are specific to individual users on the system. 
				- Each user can have their own set of environment variables that customize their shell environment and define specific configurations and settings for their user session.

				- When a user logs in, the shell reads and sets up the user`s specific environment variables based on the configuration files located in the user`s home directory. The main file used for user-specific environment variables is the .bashrc

				- they are not available to other users or  processes on the system of other user, and they don`t apply to non-interactive shells or to processes started without a user login session.


				The main places where you can define user-specific environment variables:

					1. .bashrc  file 

						- This is the most common file for defining user-specific environment variables in the Bash shell. 
						- It is executed whenever an interactive non-login Bash shell is started.	

				    2. .bash_profile or .bash_login  or .profile  file : These files are executed only once when a login shell is started. You can define user-specific environment variables in these files similar to .bashrc.	

					3. .profile.d/ directory: 

						- Some shells, like Bash, source all executable files with the .sh extension found in the ~/.profile.d/ directory. 
						- You can create a new script with the .sh extension in this directory to set user-specific environment variables.	

					Note : 
						Remember that the changes made to these files will only take effect for new shell sessions or logins. To apply the changes immediately, you can use the source command or restart the shell session.

						all these files to set user specific variable are located inside user home directory.  


Q: what is PATH varibale in ubuntu ? 
-> 
		- PATH variable is an environment variable that specifies a list of directories where the system should look for executable files when you enter a command in the terminal. It plays a crucial role in determining which programs can be executed without specifying their full paths.

		- When you enter a command in the terminal, the system searches for the executable file associated with that command in each directory listed in the PATH variable. If the executable is found in one of these directories, the command is executed. If it`s not found, you`ll receive an error indicating that the command is not recognized.

		- we can include many directory in PATH ( i.e we can export multiple PATH variables )

     export PATH=$PATH:/path/to/your/directory        // This command adds /path/to/your/directory to the end of the existing PATH variable.


	 
Q: linux file system & permissions.
-> 
		- Linux Filesystem is a tree-like structure comprised of lots of directories. 
		-  These directories are just the files containing the list of other files. 
		- Linux makes no difference between the files and directories. 
		- All the files in Linux filesystem are known as directories, and these files are categorized as follows:

			1. Ordinary files that contain data, text, images, program instructions.
			2. Special files that give access to hardware devices.
			3. Directories that contain both the ordinary and special files.  


    There are 7 colums in which describe the file/directory in linux file system
		//  eg: drwxrwxr-x 9 fa065034 fa065034 4096 Nov 10 12:45 ./

			1st column represents the file type and file permissions. Every file row begins with the file type and then specifies the access permissions associated with the files. These are the following types of files with their specific characters:
				Regular file (-)
				Directory (d)
				Link (l)
				Special File (c)
				Socket (s)
				Named pipe (p)
				Block device (b)
			2nd column represents the number of memory blocks.                                                     // 9
			3rd column represents the owner of the file or the superuser, who has the administrating power.        // fa065034
			4th column represents the group of owner/superuser.													   // fa065034
			5th column represents the file size.																   // 4096
			6th column represents the date and time when the file was created or lastly modified.				   // Nov 10 12:45
			7th column represents the name of the file or the directory.										   //  ./      directory link to previous directory

	Ownership and file permissions

	 		ownership : owner, group, other_user
			permission : r w x  // read write execute

			// eg:  drwxrw-r--     : user has rwx, group has rw , other users have r permission                
			// - means no permission

			permissions can be altered by using chmod command. 
				chmod u+x      // give user persion to execute
				chmod a-x      // revole all classes (u,g,o) the permission to execute
