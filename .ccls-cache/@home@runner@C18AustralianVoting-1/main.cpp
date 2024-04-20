#include <iostream>
#include "FileIO.h"

int main(int argc, char **argv) {
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


}