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
void FileIO::printWinnerStr(std::string cn) {
  std::cout << "WINNER: " << cn << std::endl;
  outFile << "WINNER: " << cn << std::endl;
}

bool FileIO::getVP (std::queue<int>* vp) {
  std::string line;
  getline (inFile, line);

  if (line.empty()) return false;
  
  std::istringstream ss (line);
  std::string ID;
  
  while (ss >> ID) {
    vp->push(std::stoi(ID));
  }
  
  return true;
}


FileIO::FileIO (void) {
  std::cerr << "This is the default constructor for FileIO" << std::endl;
}
FileIO::~FileIO (void) {
  std::cerr << "This is the destructor for FileIO" << std::endl;
}