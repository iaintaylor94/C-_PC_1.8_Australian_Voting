#include <iostream>
#include "Election.h"

int main(int argc, char **argv) {

  Election election (argc, argv);

  election.initCases();

  for (int i = 0; i < election.num_cases; i++) {
    
    election.initCandidates();
    election.createTree();
    election.vote_path.printTree();

    while(election.getVotePath()) {
      election.printVotePath();
      //election.vote_path.printTree();
      election.addVotePath();
    }

    election.vote_path.printTree();
  }
  
}