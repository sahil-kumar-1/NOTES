Note : commands with : ->>  like   :jumps , :q, :w etc are written in  command line mode
       commands withot : ->> like  : 0, $, ctrl+b , ctrl+f etc are written in command mode
       we can not write any command in insert mode.

/*	vim modes and how to switch between them	*/ 
	
	command mode // default mode // esc to move back to command mode from insert or command line or visual mode // 
	insert mode                  // i or insert to move from command to insert mode // this mode is used to edit text content of the document   
	command line mode            // : to move from command to command line mode    // every command in this mode starts with :
	visual mode           	     // v to move from command to visual mode 


/*	creating a new file or opening existing one if there  */

	$ vim demo.txt                // from shell command line
        :edit demno.txt               // from inside vim            (: indicates to execute the command in command line mode)


/*	saving file and exiting the vim editor		*/

					// one file is open move to insert mode edit the file 
	:w		// save( write ) the file 
	:q		// quit the vim editor ,this woill work after file has been saved    //     :wq to save the file and exit the vim editor
	:qa! or :q!     // dont save the changes in the file and exit the vim editor. 


/*	open file in read only mode	*/

	$ vim -R demo.txt		// from shell cmd line
	:view demo.txt			// from vim command line mode	


/*	getting help from vim editor	*/

	:help
	:help topic_name		// topic_name = modes , ....
	:helpgrep phrase                // phrse = navigation, ....        // to find topic_name if we dont know to use in help


/*	inserting cursor while switching from command mode to insert mode	*/

	i		// insert text before char cursor is at
	I		// brings us to begining of line cursor is in 
	a		// insert text after  // text is always inserted before the char cursor is at   // this command just moves the cursor one char right before entering in insert mode
	A		// append text at the end of line curser is in

	o		// insert an line below line where cursor is ->> then move to start of newly inserted line in insert mode
	O		// insert an line above line and move to that line 

	s		// delete current char cursor is pointing and move to insert mode
	S		// cc will do the same  //delete entire line cursor is in ->> place the cursor at begin of the line
	C		// deletes all after curser in current line ->> cursor stays at same position in insert mode.

	r 		// allows to replace the char cursor is at // we remain in command mode
	R		// open in replace mode  // when we write cahr after it gets replaced by what we type.

 	J		// join the line below after current line and enters in insert mode.
	


/*	Navigating the file in command mode	*/

	h or left_arrow    	// Move cursor to left by one position
	l or right_arrow	// Move cursor to right by one position
	k or up_arrow		// Move cursor to upward direction by one line
	j or down_arrow		// Move cursor to downward direction by one line    // 10j or 10down_arraw to move 10 lines below ->> we can do similar things with other 


	0		//  Move cursor to the beginning of current line
	$		//  Move cursor to the end of current line
	Ctrl + f 	//  Scroll down entire page
	Ctrl + b 	//  Scroll up entire page


/*	Navigating the lines in commanls line mode 	*/

	:n 	// Jump to the nth line
	:0 	// Jump to the start of file
	:$ 	// Jump to the end of file


/*	navigating words command mode	*/

	w	// Move cursor to the beginning of the next word
	e	// Move cursor to the end of the current word
	b	// Move cursor to the beginning of the previous word



/*      jumps to previous / next place cursor was , command and command line mode	*/

	:jumps 		// see the jump list (track of history of cursor maintaines by vim editor
	Ctrl + o	//  Jump back to the previous position
	Ctrl + i 	//  Jump to the next position
	





--------------------------------------------------------------------------------------------------------------------------------
/*									EDITING TEXTS 					      
	EDITING features of VIM 
	
	Buffer  : Buffer is temporary memory used by Vim. When we open a file in editor, Vim loads its contents from disk drive. 
		  These contents are stored in memory (RAM) whenever we edit a file we are actually editing file from buffer. 
		  Once we finish editing and save file that time only buffer contents are transferred to appropriate file.

	Swap files
	Cut, copy, delete, paste actions
	Undo and redo actions

	swap area :Swap area is a file created by Vim to store buffer contents periodically. 
		   While editing file our changes may be lost because of any reasons and Vim provides swap files to provide data recovery

		   :swapname           // to get the name of swap file of file being edited. 
 */
---------------------------------------------------------------------------------------------------------------------------------------
	
	x 		// delete current char 
	X		// delete char previous to cursor	
	dw		// delete entire word cursor is at
	D		// delete entire line after curser position
	dd		// delete the entire line

	Y or yy         // copies entire line 	

	P 	        // paste the copied content before cursor ( captial P ) 
	p		// paste after cursor
	
							
note : to perform a multi line/ multi word action just use a number with command    // eg : 3dd  to delete 3 lines // 3u for 3 undo's 

	u			// undo                        
	ctrl + r    or :red	// redo



----------------------------------------------------------------------------------------------------------------------------------
/*								VIM SEARCHING                                      	*/
----------------------------------------------------------------------------------------------------------------------------------

searching in file 
				search related settings	

	:set incsearch     // enabling incremenal searching
	:set hlsearch      // enabling highlight searching
	:set noincsearch
	:set nohlsearch

				Search in forward direction

	/<expression> 	// Search expression in forward direction                  // eg: /vim
	n 		// Find next occurrence. This is same and find next
	N 		// Find previous occurrence. This is same as find previous
	// 		// Repeat previous forward search

				
				search in backward direction ( search will start from end of the file )

	?<expression> 	// Search expression in backward direction
	n 		// Find previous occurrence. This is same and find previous
	N 		// Find next occurrence. This is same as find next
	?? 		// Repeat previous backward search
			

				Search word under cursor ( Place cursor under any word and execute )

	* 	// Search next occurrence of current word
	# 	// Search previous occurrence of current word	 


				Search in multiple files

	
	:vimgrep Jarvis *.txt          // search for Jarvis in all .txt file

	:cn 		// Go to next occurrence of expression
	:cN 		// Go to previous occurrence of expression
	


----------------------------------------------------------------------------------------------------------------------------------
			Vim working with multiple things 
----------------------------------------------------------------------------------------------------------------------------------





----------------------------------------------------------------------------------------------------------------------------------
			vim maerkers -	bookmarking in Vim  (  command mode)
----------------------------------------------------------------------------------------------------------------------------------

	ma		// creates a bookmark of name a ->> which points to line && char where cursor is currently
	`a		// takes to exact pos of char bookmarked
	'a 		// takes to start of the line of bookmark

	:marks 		// show all bookmarks
	:delmarks a	// delets bookmark a 

		global bookmar : bookmark name with captial letters  ->> can be accesses when multiple files are opened.
