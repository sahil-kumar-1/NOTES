Q: what is HEAD in git ? 
-> 
    - "HEAD" refers to a special pointer or reference that represents the current state of your Git repository. It points to the latest commit in the branch you are currently working on, which is often the tip of the branch

    Current Branch Pointer : HEAD is essentially a pointer or reference to the branch or commit that you have checked out or are currently working on.

    Commit Reference : When you make a new commit, the HEAD pointer is updated to point to that new commit, signifying that the branch has advanced to this new state.

Q: what is commit reference & commit hash ? 
-> 
     commit reference is a symbolic name or pointer that points to a specific commit. It`s a human-readable way of referring to a commit, branch, tag, or other Git objects.   

     Common commit references include:
        - Branch Names : Branches are references that point to a specific commit, and they are often used to track the latest changes in a line of development.
        - Tag Names : Tags are references that point to specific commits and are typically used to mark important points in the commit history, such as releases.
        - HEAD : As mentioned earlier, HEAD is a special reference that points to the currently checked-out commit or branch. 

     A commit hash, often referred to as a "commit ID" or "SHA-1 hash",
     it uniquely identifies that commit and is used for referencing it in various Git operations.   