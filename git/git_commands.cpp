
Commit History:   When you make a commit in Git, a snapshot of the entire project`s working directory is taken, including all the files that are tracked by Git. This snapshot is then stored in the commit history as a unique state of your project at that point in time. Each commit in the history points to the previous commit(s), creating a chain of commits that captures the project`s evolution.

Staging Area (Index):   The staging area (also known as the index) is a temporary storage area where you prepare changes before committing them. When you use the git add command, you`re effectively adding a copy of the changes to the staging area. The staging area acts as a buffer between your working directory and the next commit. It allows you to selectively choose which changes you want to include in the upcoming commit.

    - the content of files that have been committed is stored in the Git repository`s commit history, and a copy of that content is also present in the staging area when you prepare a commit.


working with branch in git. 

git clone clone_url              // cloning the default branch of repository. 

git clone -b branch-name repository-url   // way to clone from branch other than default branch.

git branch                       // lists all the branch in current git working directory.

git branch branch_name           // creating new branch ( with same code in working area as current area )

git branch -d branch_name        //  to delete a branch which is merged with the current brach on which we are executing this code.  

git branch -D branch_name        //  to delete a branch which is not merged with the current brach on which we are executing this code.  

git push origin --delete branch-name    // deleting a branch on remote repository

    U : unstaged or untracked      // never added to staging area.   
    A : added to Staging area for first time. 
    C : commited                    // copy of file in staging area and commited one are same. 
    M : modified ( some thing added to staging area which makes it different from commited copy)     // copy of file in staging area and commited one are different. 


    "git add A.txt B.cpp src/"  : adding specific files / directory to staging area.
    "git add -A"                : add all files in the working directory to staging area. 

    git commit -m "message"     : commiting teh staged code.


    1. we are creating a new branch from branch we are working. 
    -> all U,A,C files along with its content will be available in working area when we switch to new branch. 

    2. what will happen when we move to different branch without commiting all the code in the current branch ?
        
        suppose we are at master branch with files. 

            A   : all code of A is commited.                                         // status C
            B,C : was included in prev commit but having some code which is tracked  // status M
            D   : was added in tracked but this file was never commited before       // status A
            E   : this file is untracked                                             // U

       1. Now suppose we create a new branch temp_branch move there and commit all the above file in that branch. 

            when we'll checkout into master again only commited snap of files will be there. 
                A   : all code will be there as this file was commited.
                B,C : code in staging area was lost that was not commited, commited code persisted    // code from commited snap will be copied to staging area. 
                D,E : deleted as these files were never commited before. 
            
       2. when we move to a branch already having all these files A,B,C,D,E 

       /*
                error: Your local changes to the following files would be overwritten by checkout:
                        B.cpp
                        C.cpp
                        D.cpp
                Please commit your changes or stash them before you switch branches.
                error: The following untracked working tree files would be overwritten by checkout:
                        E.cpp
                Please move or remove them before you switch branches.
                Aborting       
       */ 

        // Be carefull in case 1 as in case 2 git will throw error.




deleted files in a branch

    when we delete a commited file by git rm index.js .
    -> git removes the file from working area & adds the delete/change to stagin area. 
    -> now if we commit the file will be removed in this commit. ( as only staged files & codes snapshort is saved in commit )

    when we delete a file has changes staged in index ( has new code in staging area that is not in last commit ) by git rm index.js
    -> git will not allow us to delete this file.  now we have two options. 
    -> git rm --cached index.js // removes the file from staging area ( file will not will there in next commit ),   but this command keeps the file in working area. 
    -> git rm -f index.js       // removes the file from staging area as well as working area. 

    How to recover files deleted by  "git rm index.js"  ? 
        1. if file is present in prent in the last commit.     
            ->  "git restore --staged index.js index.css"      // unstaged the change i.e deletion of file from staging area. i.e copies back the content of file from last commit.
            ->  "git restore index.js index.css"               // copies file from staging area to working area.

        2. if the file is present in some commit 
            -> "git restore <commit-reference> -- <path-to-deleted-file>"


        3. completely discard the changes in staging area and working area && restore the file to its state in a specific commit.
            ->  "git restore --staged --source=<commit> <file>"
            // we can use the commit hash of different branch commit too.
     


git config --get remote.origin.url          // get url of current remote git repository (pull url)

git add pom.xml src/                        // to add changes to stagin area

git commit -m"commit mesage "               // to make a commit to current branch 


git log                                     // to see the commit logs in current branch 
git log -n <number>                         // to see last n commit details

    /* commit e41debb1b1bdfe1b40511160107f799b19cf60a0 (HEAD -> react_hooks)         // commit hash
       Author: Sahil Kumar <sahil.kumar@naukri.com>
       Date:   Mon Aug 7 12:36:49 2023 +0530

        useRef hook                                                               // message. 
    */

git show <commit-hash>                       // display the changes made in the specified commit.


git fetch --all                              // fetch all new branch from origin created afetr we pulled the repo.  
git checkout branch_name                     // switch to existing branch
git checkout -b branch1 branch2              // creates a new branch named branch1 starting from the current state of branch2

git checkout <commit-hash>                        // brings code of this commit in detached branch.
git checkout -b new-branch-name <commit-hash>     // brings code of this commit in new-branch-name branch. 


        /* 
            - This will load the entire repository state at the specified commit. 
            - However, please note that you will be in a "detached HEAD" state, which means any changes you make won't be on any branch. 

            - So after we are on detached branch we have two option.
                1. "git switch -" : discard this which will bring us into normal flow branch flow from where we created this detached branch. 
                2. "git switch -c <new-branch-name> " : to create a new branch to retain commits you create in this detached branch. 

             NOte : in case of   git checkout <commit-hash>  &&  git checkout -b new-branch-name <commit-hash>
                    - all the commited code  in branch from which we are taking out particular commit will remain unaffected 
                    - as we are taking specific commit code in detached branch or new branch. 

             Note : be causious in case of git checkout <commit-hash> as if we move to a different branch without commiting the code in a new branch data will be lost.     

                    git checkout <commit-hash> primarily affects your working directory and the HEAD pointer, potentially leading to a detached HEAD state if used to checkout a specific commit. It doesn't directly alter commit history.
          
        */   


git revert <commit-hash>
git revert --continue           // execute after adding to staging area. this will be create a commit with same commete  
git revert --abort
    
        /*
            -  Git analyzes the changes made in that commit && current code.
            -  git gives us merge conflicts 
            -  we resolve conflicts 
            -  now we create a new commit for this code. 
            
            NOte : prev commit history remains unaffacted 
                   this commit is added as a new commit. 

            A -- B -- C -- D -- E -- F (HEAD)
                    \
                    Revert C ( new commit will be created on top of F )  
        */


// hint: After resolving the conflicts, mark them with
// hint: "git add/rm <pathspec>", then run
// hint: "git revert --continue".
// hint: You can instead skip this commit with "git revert --skip".
// hint: To abort and get back to the state before "git revert",
// hint: run "git revert --abort".

git cherry-pick <commit-hash>

    /*
    
        - git cherry-pick allows you to apply the changes from one or more commits onto your current branch. 

        NOTE : When deciding between git revert and git cherry-pick, consider your goal. 
        1. If you want to undo a commit and maintain a clean history, use git revert. 
        2. If you want to selectively apply changes from one commit onto another branch, use git cherry-pick.
    */



git stash : allows you to temporarily save changes in your working directory that are not ready to be committed yet. It`s a way to store unfinished work so that you can switch to a different branch or perform other operations without committing incomplete changes.


    1. git stash save "message"       // creating a stash 

    2. git stash list                 // to see list of all stash stored. 
    
        - most recent stash has the index 0. 
        - stash of all branch are at same place ( branch name is shown ).  
        //stash@{0}: On master: branch: master learning about git stash

    3. git stash apply stash@{i}      // to bring the code of stash with index i to working directory. 
       git stash apply                // apply most recent stash. 

    4. git stash drop stash@{2}        // drop the stash with index 2      
       git stash drop                  // drop the most recent stash i.e with index 0 
    


git diff    

    0. git diff         // shows the difference of file in working area vs staging area. 
       git diff release // shows the difference of the file in working area vs copy in release branch (latest commit copy).  

    1. git diff <commit>..<current-branch>    // <commit> is hash code of commit & <current-branch> is name of current branch
                                              // Note : commit_hash can be of any branch.  
       git diff -u <commit>..<current-branch>  // to see the output in more readable format. 

    2. comparing specific files between the two commits  // NOte : commit_hash can be of different branches

        git diff <commit_hash_1>:src/main.js <commit_hash_2>:src/main.js    

        git diff feature:myfile.txt master:myfile.txt       // comparing files of different branches - latest commits will be compared. 



git restore .             // restores all file to last commit 
 