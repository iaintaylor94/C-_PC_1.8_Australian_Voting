#ifndef ELECTION_H
#define ELECTION_H

#include "FileIO.h"
#include "Candidate.h"
#include "VotePath.h"

class Election : public FileIO, public Candidate {

  static const int MAX_NUM_CANDIDATES = 20;

protected:
  int num_cases;
  int num_candidates;
  Candidate candidates [MAX_NUM_CANDIDATES];

public:
  Election (int argc, char **argv) : FileIO (argc, argv) {
    std::cout << "This is the constructor for Election" << std::endl;
  };
  ~Election (void) {};

  void initCandidates (void);

  Vote_path vote_path;


};
#endif