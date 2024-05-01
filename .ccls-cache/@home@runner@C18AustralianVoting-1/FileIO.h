#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <sstream>

#include <queue>

#include "FileHandling.h"

class FileIO : public FileHandling {

protected:
  void getNumCandidates (int*);
  void getCandidateName (std::string*);
  bool getVP(std::queue<int>*);
  void printWinner (std::string);

public:
  FileIO (void);
  FileIO (int argc, char **argv) : FileHandling (argc, argv) {
    std::cerr << "This is the constructor for FileIO" << std::endl;
  };
  ~FileIO (void);

  void getNumCases (int*);

};
#endif