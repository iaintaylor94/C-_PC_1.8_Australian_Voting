#ifndef VOTEPATH_H
#define VOTEPATH_H

#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>

struct Vote {
  bool isEliminated;
  std::vector <int> path;
  std::vector <Vote*> branches;

  int num_votes;
};

class Vote_path {
  static const int MAX_NUM_CANDIDATES = 21;
  int num_candidates;
  std::vector <int> path;
  bool isEliminated [MAX_NUM_CANDIDATES];
  Vote root;

  bool inPath (std::vector<int>, int);
  void initVote (Vote*, std::vector<int>, int);

  void printNumVotes (int);
  void printPath (std::vector<int>);
  void printVote (Vote*, std::vector<int>, int);
  void deleteVote (Vote*);

  std::vector<int> secondPreference;

public:
  Vote_path (void) {};
  ~Vote_path (void) { deleteTree(); };

  void printTree (void);
  void createTree (int);
  void deleteTree (void);
  void updateVotePath (Vote*, std::queue<int>);
  void addVP(std::queue<int>);

  void eliminateVote (Vote*, int);
  std::vector<int> eliminateLoser (int);
};


#endif