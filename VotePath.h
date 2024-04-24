#ifndef VOTEPATH_H
#define VOTEPATH_H

#include <vector>
#include <iostream>

struct Vote {
  std::vector <int> path;
  std::vector <Vote*> branches;
};

class Vote_path {
  static const int MAX_NUM_CANDIDATES = 21;
  int num_candidates;
  std::vector <int> path;
  Vote root;

  bool inPath (std::vector<int>, int);
  void initVote (Vote*, std::vector<int>, int);

public:
  Vote_path (void) {};
  ~Vote_path (void) {};

  void printPath (std::vector<int>);
  void printVote (Vote*, std::vector<int>, int);
  void printTree (int);
  void createTree (int);
};


#endif