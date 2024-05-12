
Commit History:   When you make a commit in Git, a snapshot of the entire project`s working directory is taken, including all the files that are tracked by Git. This snapshot is then stored in the commit history as a unique state of your project at that point in time. Each commit in the history points to the previous commit(s), creating a chain of commits that captures the project`s evolution.

Staging Area (Index):   The staging area (also known as the index) is a temporary storage area where you prepare changes before committing them. When you use the git add command, you`re effectively adding a copy of the changes to the staging area. The staging area acts as a buffer between your working directory and the next commit. It allows you to selectively choose which changes you want to include in the upcoming commit.

    - the content of files that have been committed is stored in the Git repository`s commit history, and a copy of that content is also present in the staging area when you prepare a commit.


HEAD pointer VS branch pointer.

    /*
    HEAD:
        - The HEAD is a reference to the currently checked out commit in the repository.
        - It is essentially a symbolic reference that points to the tip of the current branch, indicating which commit is currently being worked on in the working directory.
    
        - The HEAD can be in one of two states:
            . Detached: When the HEAD points directly to a specific commit rather than to a branch. This occurs, for example, when you check out a commit by its hash.
           
            . Attached: When the HEAD points to the tip of a branch, indicating that the repository is in a normal working state.
    
        In summary, the HEAD determines which commit is currently being worked on in the working directory.
    
    
    Branch Pointer:
        - A branch pointer is a reference to the tip of a branch in the commit history.
        - It is a lightweight movable pointer that is used to label a specific commit in the history of the repository.
    
        - When you create a new branch, Git creates a new branch pointer that points to the same commit as the current HEAD. As you make new commits, the branch pointer moves forward to point to the latest commit on the branch.
    
        - Each branch in Git has its own branch pointer, allowing multiple branches to progress independently from each other.
    
        - Branch pointers provide a way to organize and manage the commit history by grouping related changes together on separate branches.    
    
    */


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

        git log --author=<author name> <branch name> -n<number>
            
                /*
                    git log --author="Sahil Kumar <sahil.kumar@naukri.com>"           // lists the commit of particular author in current branch.
                    git log --author="Sahil*"                                       // lists the commit of authors whose name start with sahil.
                */ 


git show <commit-hash>                       // display the changes made in the specified commit.


git fetch --all                              // fetch all new branch from origin created afetr we pulled the repo.  


git checkout branch_name                     // switch to existing branch

    git checkout -b branch1 branch2                   // creates a new branch named branch1 starting from the current state of branch2

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

    git checkout BranchB -- x.txt         // checkouts the file x.txt  ( i.e brings the file x.txt from BranchB in current branch)
                                               

git revert

    git revert <commit-hash>
    git revert --continue           // execute after adding to staging area. this will be create a commit with same comment 
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

    git cherry-pick  <commit-hash>         
        // this will bring the changes in the <commit-hash> to current branch
        // no conflict in bringing changes -> creates an commit of those chages.
        // conflict in bringing changes    -> we need to manually resolve the conflicts & then we can commit or whatever. 
    
    /*
        case 1: 
            - in commit A we added function X(){ print(a) }
            - in commit B we modified it to X(){ print(b) }
            - now we are in branch where X(){....} does not exists. 
            - when we'll cherry-pick commit B 
            - no changes will be applied in current branch as -> code which was changed in commit B is  not in current branch. 

            CONCLUSION : cherry-pick will apply on those changes to current branch whose original state is present in current branch which was modified in that commit. 
    */

     useful flags.

    --no-commit
        // git cherry-pick --no-commit <commit-hash>    
        // just brings the changes to current branch, does not adds a commit even if there is no conflict.     


git merge release             // merges branch release in current branch with default commit message.

    git merge release -m"merge commit message              "        // providing custom commit message.
    
    useful flags
      
      --no-commit 
        // git merge --no-commit release         // does not creates a commit ( just stops before commiting i.e new incomming code will be staged )


git stash : allows you to temporarily save changes in your working directory that are not ready to be committed yet 
            It`s a way to store unfinished work so that you can switch to a different branch or perform other operations without committing incomplete changes.

            NOTE : when we use stash staged & un-staged changes get saved in stash 

    1. git stash save "message"       // creating a stash 

    2. git stash list                 // to see list of all stash stored. 
    
        - most recent stash has the index 0. 
        - stash of all branch are at same place ( branch name is shown ).  
        //stash@{0}: On master: branch: master learning about git stash

    3. git stash apply stash@{i}      // to bring the code of stash with index i to working directory. 
       git stash apply                // apply most recent stash. 

    4. git stash drop stash@{2}        // drop the stash with index 2      
       git stash drop                  // drop the most recent stash i.e with index 0 
       git stash clear                 // drop all the stash entries.

    5. git stash show                 // shows the files that are stashed of most recent stash i.e stash@{0}.
       git stash show stash@{i}       //  
          
    


git diff    

    0. git diff         // shows the difference of file in working area vs staging area. 
       git diff release // shows the difference of the file in working area vs copy in release branch (latest commit copy).  

    1. git diff <commit>..<current-branch>    // <commit> is hash code of commit & <current-branch> is name of current branch
                                              // Note : commit_hash can be of any branch.  
       git diff -u <commit>..<current-branch>  // to see the output in more readable format. 

    2. comparing specific files between the two commits  // NOte : commit_hash can be of different branches

        git diff <commit_hash_1>:src/main.js <commit_hash_2>:src/main.js    

        git diff feature:myfile.txt master:myfile.txt       // comparing files of different branches - latest commits will be compared. 

    flags which can be used with above commands

    git diff --staged               // show the diff of staging vs commited code. 
    git diff --name-only            // name of file having diff in staging vs working area 


git restore .             
        // restores all file in working area 
        // brings content from  staging area ( unstaged changes are removed )
    
    git restore src/abc/exaple.java           // restoring  specific file ( we can restore directory too )

    git restore --staged   
        // retores all file in staging area. 
        // all uncommited changes that are staged will be moved to working area ( non staged state )

    /*
        - while both git reset and git restore are used to manipulate the state of your repository, 
        - git reset primarily deals with moving the HEAD and index to a specific state, while 
        - git restore primarily deals with restoring files in the working directory or index from a specific source.
    */

    git restore <commit-hash> src/abc/example 
    git restore --source=<commit-hash>      src/abc/example    // works same without --source 

     // we can use <branch> <tag> too instead of <commit-hash>



git reset 
        /*
         git reset is a mixed reset, meaning 
         it moves the HEAD to the specified commit while leaving the index and the working directory unchanged. It unstages changes but leaves the modified files in the working directory.
        */ 

    git reset --hard 
        /*
             reset that moves the HEAD, index, and working directory to a specific state, discarding all changes in the index and the working directory.

            It resets both the index and the working directory to match the specified commit. 
            Any changes in the index and working directory that are not in the specified commit will be lost.
            
            Useful for completely undoing local changes and reverting the repository to a clean state.
        
        */

    git reset --hard <commit-hash>    
    git reset --hard <branch>    

        /*
            - HEAD pointer & Branch pointer move to specific commit  ( last commit in branch in case of branch)
            - index (staging area ) & working area are matched to specified commit 

            - Lost Commits: Commits that were made after the specified commit will no longer be part of the history of the current branch. 
                
                . They will not be immediately visible in the commit history, but they are still present in the Git repository until they are garbage collected by Git's cleanup mechanisms. 

            - Reflog can be used to recover any lost commit, if needed. 
        */
