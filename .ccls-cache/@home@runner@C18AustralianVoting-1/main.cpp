#include <iostream>
#include "Election.h"

int main(int argc, char **argv) {

  Election election (argc, argv);

  // Num Cases
  election.initCases();

  for (int i = 0; i < election.num_cases; i++) {

    // Init
    election.initCandidates();
    election.createTree();
    election.vote_path.printTree();
    
    // Create Vote Path Data Structure
    while(election.getVotePath()) {
      election.printVotePath();
      election.addVotePath();
    }

    election.vote_path.printTree();

    // Process Votes - find winner/winners
    while (true) {
      int winnerID = election.isWinner();
      // Find winners
      if (election.allVotesCounted()) {
        election.printWinners();
        break;
      }
        // Find winner
      else if (winnerID) {
        election.printWinner(winnerID);
        break;
      }
      else {
        // Eliminate loser(s)
        election.getNumLostVotes();
        election.eliminateLosers();
      }
    }
  }
}