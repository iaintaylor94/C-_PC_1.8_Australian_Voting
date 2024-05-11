#ifndef ELECTION_H
#define ELECTION_H

#include <queue>
#include <climits>

#include "FileIO.h"
#include "Candidate.h"
#include "VotePath.h"

class Election : public FileIO, public Candidate {

  static const int MAX_NUM_CANDIDATES = 20;
  int num_candidates;
  Candidate candidates [MAX_NUM_CANDIDATES];
  std::queue<int> votePathInput;

  int numLostVotes = 0;

  void updateVotes (std::vector<int>);

public:
  Election (int argc, char **argv) : FileIO (argc, argv) {
    std::cout << "This is the constructor for Election" << std::endl;
  };
  ~Election (void) {};

  int num_cases;

  void initCases (void);
  void initCandidates (void);

  void getNumLostVotes (void);
  void eliminateLoser (int);
  void eliminateLosers(void);

  int isWinner (void);
  bool allVotesCounted (void);
  void printWinner (int);
  void printWinners (void);
  

  Vote_path vote_path;
  void createTree (void);
  bool getVotePath (void);
  void addVotePath(void);
  void printVotePath(void);
};
#endif