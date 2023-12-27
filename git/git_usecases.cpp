

1. To make a file in BranchA the same as a file in BranchB, you can achieve this by checking out the file from BranchB and updating BranchA. Here are the steps:

    git checkout BranchA   // First, make sure you are on BranchA

    git checkout BranchB -- x.txt // Next, you can use the git checkout command to copy the version of the file from BranchB into BranchA. Assuming the file you want to update is called x.txt:

        // This command will replace the content of x.txt in BranchA with the content from BranchB.

    git commit -m "Update x.txt in BranchA to match BranchB"     // Finally, commit the changes in BranchA to save the updated file:

        // After completing these steps, the x.txt file in BranchA will be the same as the x.txt file in BranchB.



Q:  how to move the head to specific commit ?
-> 
    git reset --hard <commit_hash> 

        - resets both the HEAD and the working directory to the specified commit.   (It`s like forcefully moving your branch pointer to a different commit.)
        - It effectively discards all changes in your working directory and stages. 
               // all commited//staged/unstaged changes will be discarded after the specific commit  ( git commit history also changes )  


Q: how to merge code ? 
-> git merge release -m"message"         // merge release in current branch


    /* resolving conflicts. 
    
        <<<<<<< HEAD
        import com.ie.naukri.ccsubalib.main.models.UBARequestModel;
        =======
        >>>>>>> release
        

    -->  code b/w  <<<<<< HEAD  && =======  is code in working area . // our code 
    -->  code b/w  ====== && >>>>>>release  is code from release      // release code 

     now manually remove or keep code we want to.    
    
    */


Q: to see the content of specific commit
-> 
    git show <commit_hash>  // shows the changes made in the particular commit.     

Q: to see the files which are different from particular branch/commit.
-> 
git diff --name-only release        // list the files whose content are different from release. 

