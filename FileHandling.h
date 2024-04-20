#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <string>

class FileHandling {


protected:
  std::ifstream inFile;
  std::ofstream outFile;


public:
  FileHandling (void);
  FileHandling (int argc, char **argv);
  ~FileHandling ();

};
#endif