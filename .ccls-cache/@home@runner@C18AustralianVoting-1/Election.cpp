#include "Election.h"

void Election::initCases(void) {
  // Initialize cases
  getNumCases(&num_cases);
}
void Election::initCandidates (void) {
  getNumCandidates (&num_candidates);
  // Initialize candidates
  candidates[0].isWinner = false;
  candidates[0].isEliminated = true;
  for (int i = 1; i < num_candidates + 1; i++) {
    getCandidateName(&candidates[i].name);
    candidates[i].numVotes = 0;
    candidates[i].isWinner = false;
    candidates[i].isEliminated = false;
  }
}

void Election::getNumLostVotes(void) {
  numLostVotes = INT_MAX;
  // Get num lost votes
  for (int i = 1; i < num_candidates; i++) { // 1 => candidates start at 1
    if (candidates[i].numVotes < numLostVotes) {
      numLostVotes = candidates[i].numVotes;
    }
  }
}

void Election::updateVotes (std::vector<int> votes) {
  for (auto it = votes.begin(); it != votes.end(); ++it) {
    int index = it - votes.begin();
    candidates[index].numVotes += votes[index];
  }
}
void Election::eliminateLosers(void) {
  for (int i = 1; i < num_candidates; i++) { // 1 => candidates start at 1
    if (candidates[i].numVotes == numLostVotes) {
      std::vector<int> votes;
      candidates[i].isEliminated = true;
      votes = vote_path.eliminateLoser (i); 
      updateVotes(votes);
    }
  }
}

int Election::isWinner (void) {
  // Check if there is a winner
  int totalNumVotes = 0;
  for (int i = 0; i < num_candidates; i++) {
    totalNumVotes += candidates[i].numVotes;
  }
  double numToWin = (double) totalNumVotes / 2;

  for (int i = 0; i < num_candidates; i++) {
    if (candidates[i].numVotes > numToWin) {
      candidates[i].isWinner = true;
      return i;
    }
  }
  
  return 0;
}
bool Election::allVotesCounted (void) {
  // All candidates must be either: isWinner || isEliminated
  for (int i = 1; i < num_candidates; i++) {
    if (!candidates[i].isWinner && !candidates[i].isEliminated) return false;
  }
  return true;
}
void Election::printWinner (int i) {
  printWinnerStr(candidates[i].name);
}
void Election::printWinners (void) {
  for (int i = 0; i < num_candidates; i++) {
    if (!candidates[i].isEliminated) {
      printWinnerStr(candidates[i].name);
    }
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