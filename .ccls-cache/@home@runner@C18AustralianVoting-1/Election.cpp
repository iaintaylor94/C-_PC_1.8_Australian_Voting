#include "Election.h"

void Election::initCases(void) {
  // Initialize cases
  getNumCases(&num_cases);
}
void Election::initCandidates (void) {
  getNumCandidates (&num_candidates);
  // Initialize candidates
  for (int i = 0; i < num_candidates; i++) {
    getCandidateName(&candidates[i].name);
    candidates[i].numVotes = 0;
    candidates[i].isWinner = false;
    candidates[i].isEliminated = false;
  }
}

bool Election::getVotePath() {
  std::queue<int> empty;
  std::swap(votePathInput, empty);
  return getVP(&votePathInput);
}
void Election::addVotePath() {
  vote_path.addVP(votePathInput);
}
void Election::printVotePath() {
  std::queue<int> copy1, copy2;

  while (!votePathInput.empty()) {
    copy1.push(votePathInput.front());
    copy2.push(votePathInput.front());
    votePathInput.pop();
  }

  std::swap(copy1, votePathInput);

  std::cout << "Vote Path: ";
  while (!copy2.empty()) {
    std::cout << copy2.front();
    copy2.pop();
  }
  std::cout << std::endl;
}

void Election::createTree () {
  vote_path.createTree(num_candidates);
}