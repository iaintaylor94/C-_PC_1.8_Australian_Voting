#include "Election.h"

void Election::initCandidates (void) {
  // Initialize candidates
  for (int i = 0; i < num_candidates; i++) {
    getCandidateName(&candidates[i].name);
    candidates[i].numVotes = 0;
    candidates[i].isWinner = false;
    candidates[i].isEliminated = false;
  }
}