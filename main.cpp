#include <iostream>
#include "Election.h"

int main(int argc, char **argv) {

  Election election (argc, argv);

  election.vote_path.createTree(3);
  std::cout << std::endl;
  election.vote_path.printTree(3);
  
  /*
  FileIO fileIO (argc, argv);

  int numCases; 
  fileIO.getNumCases (&numCases); 
  std::cout << "numCases = " << numCases << std::endl;
  
  int numCandidates; 
  fileIO.getNumCandidates (&numCandidates); 
  std::cout << "numCandidates = " << numCandidates << std::endl;

  std::string canName;
  for (int i = 0; i < numCandidates; i++) {
    fileIO.getCandidateName (&canName);
    fileIO.printWinner(canName);
  }
  */
  
}