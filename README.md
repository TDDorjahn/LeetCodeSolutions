## Welcome
This is a repo for my solutions to the LeetCode problems that I do. These aren't necessarily the best solutions, but the best solutions that I could come up with. These solutions are to look at or learn from, not to use in your solutions. Mainly, this repo is here so that people don't have to hunt for my LeetCode profile when they want to see my LeetCode solutions from elsewhere. 

### Structure
**Solution Folder**
The repo contains folders of problems that I have worked on. They are named with the problem number first and with the name of the problem. As an example, the first problem is 1. Two Sum, so it'll be listed as `1_Two_Sum`, which each folder can be called a `solution folder.`
**Notes**
In each `solution folder`, there will be a file `notes.md`. Each notes file in the solution folders will mention what the problem is, my thought process before solving it, and solution explanations. Not every solution is posted nor mentioned in these notes, however, things such as lessons learned from failures, different approaches, and more efficient solutions are described. **Only the solutions mentioned in the notes are posted on the repository.** Some of the notes will contain *Afterthoughts*, but highly unlikely. The afterthoughts are for solutions I wanted to make, but didn't see a feasible outcome.
**Solution Attempts**
In each `solution folder` will be folders labeled `sol #`. These correspond to the solution numbers posted in the notes. These will provide the code for the `Solution class` that LeetCode provides and the necessary includes to work with the class. An example file would look like:

    #include <vector> //not provided by leetcode
    using std::vector; //not provided by leetcode
    
    class Solution {
    public:
    		... Body ...
    
    };
It'll look pretty similar to the original problem, but it'll come with the proper include directives and alias any data structures that LeetCode wants us to use where they've done away with explicit namespaces. All files to each solution attempt for the problem is named `main.cpp`, just for simplicity's sake.