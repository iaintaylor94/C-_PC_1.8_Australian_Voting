#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>

struct Candidate {
  std::string name;
  int numVotes;
  bool isWinner;
  bool isEliminated;
};

#endif