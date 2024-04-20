#ifndef VOTEPATH_H
#define VOTEPATH_H

struct vote_path {
  static const int MAX_NUM_CANDIDATES = 21;
  bool isEliminated;
  int numVotes;
  vote_path *vote_path_branches [MAX_NUM_CANDIDATES];
};


#endif