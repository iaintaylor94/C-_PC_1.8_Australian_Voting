# Programming Challenges C++
## Problem 1.8 Australian Voting[^1]
### Problem description
This program determines the winner of an Australian election, where each voter ranks the candidates from most favouite to least favouite, and this order is used to calculate the winner. Initially only the first preference is used to test if there is a winner. If a candidate has more than 50% of these votes, they are the winner. If there is no outright winner after this step, the candidate in last place is eliminated and the second choice of their voters is added to the number of votes for the relevant candidates. This process continues until there is a winner or the remaining candidates are tied.


The input consists of:
1. A single line containing the number of cases.
2. A blank line.
3. A single line containing the number (n <= 20) of candidates.
4. 'n' lines containing the names of the candidates (<= 80 chars).
5. Up to 1000 lines follow containing the priorities of the candidates for each voter.
6. A blank line signals the end of the input for that case.


The output is either:
1. A single line containing the name of the winner.
2. Several lines containing the names of those who are tied. 


### Example 
>**Input**                                                                 
>1                                                          
>                                              
>3                                
>John Doe                                             
>Jane Smith                                                  
>Jane Austen                                            
>1 2 3                                           
>2 1 3                                             
>2 3 1                                        
>1 2 3                                           
>3 1 2                                                                                            

>**Output**
>John Doe                                                                    


### Problem solution
**FileHandle class - opens and closes files**

**FileIO class - gets input from file and prints result to output (takes derived member as argument)**
1. getNumCases(int*)
2. getNumCandidates(int*)
3. getCandidateName(char*)
4. printWinner(char*)

**A "candidate" struct contains:**
1. The candidate name.
2. The number of votes for that candidate.
3. bool winner - outright winner
4. bool isEliminated - draw

**An "election" class will contain:**
1. The number of cases.
2. The number of candidates.
3. An array of candidates.
4. A *vote_path, points to vote_path tree.

**Each vote_path struct contains:**
1. A bool "isEliminated"
2. An int "numVotes"
3. An array of "*vote_path"
If the candidate branch has been visited by the upper nodes, its pointer is NULL.

**The methods of the "election" class are:**
1. initCandidates()
2. isWinner() - sets candidate.winner = true (outright winner) -- for (candidates) if (winner) printWinner()
3. allVotesCounted() (draw) -- for (candidates) if (!isEliminated) printWinner()
4. findLast() - to eliminate

**The methods acting on the "vote_path tree" are:**
1. Create tree (structure)
2. Initialize node data (bool isEliminated, int numVotes, *vote_path vp[])
3. UpdateVotes() - recursive
4. Eliminate Candidate(findLast()) - update candidate struct - recursive

**Optional:**
1. Function overloading (cout / ofstream)
2. Operator overloading (<< / >> / ++)
3. Templates


### Bug Checklist
- [1] NA

[^1]: Programming Challenges By S.Skienna and M.Revilla, page 25