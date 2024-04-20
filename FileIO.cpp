#include "FileIO.h"


void FileIO::getNumCases (int *nc) {
  // Get num cases
  inFile >> *nc;

  // Strip empty line
  std::string line;
  getline(inFile, line);
}
void FileIO::getNumCandidates (int *nc) {

  inFile >> *nc;

  // Strip empty line ???????
  std::string line;
  getline(inFile, line);
}
void FileIO::getCandidateName (std::string *cn) {
  std::string line;
  getline (inFile, line);
  *cn = line;
}
void FileIO::printWinner (std::string cn) {
  std::cout << cn << std::endl;
  outFile << cn << std::endl;
}




FileIO::FileIO (void) {
  std::cerr << "This is the default constructor for FileIO" << std::endl;
}
FileIO::~FileIO (void) {
  std::cerr << "This is the destructor for FileIO" << std::endl;
}