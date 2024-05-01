#ifndef ELECTION_H
#define ELECTION_H

#include <queue>

#include "FileIO.h"
#include "Candidate.h"
#include "VotePath.h"

class Election : public FileIO, public Candidate {

  static const int MAX_NUM_CANDIDATES = 20;
  int num_candidates;
  Candidate candidates [MAX_NUM_CANDIDATES];
  std::queue<int> votePathInput;

public:
  Election (int argc, char **argv) : FileIO (argc, argv) {
    std::cout << "This is the constructor for Election" << std::endl;
  };
  ~Election (void) {};

  int num_cases;
  // initCases();

  void initCases (void);
  void initCandidates (void);

  bool getVotePath (void);
  void addVotePath(void);
  void printVotePath(void);

  Vote_path vote_path;
  // void printTree (void);
  // void createTree (void);
  // void deleteTree (void);
  // void updateVotePath (Vote*, std::vector<int>);
  // void addVotePath(std::vector<int>);

  void createTree (void);


};
#endif