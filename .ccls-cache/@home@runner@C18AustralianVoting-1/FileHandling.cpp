#include "FileHandling.h"

FileHandling::FileHandling (void) {
  // Default Constructor
  std::cerr << "This is the default constructor, IO files are not created" << std::endl;
}

FileHandling::FileHandling (int argc, char **argv) {
  std::cerr << "This is the constructor for FileHandling" << std::endl;
  // Test num arguments
  if (argc != 2) std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;

  std::string file_name = argv[1];
  // Open Input
  inFile.open(file_name);
  if (inFile) std::cerr << "File " << file_name << " opened" << std::endl;
  else std::cerr << "File " << file_name << " not opened" << std::endl;

  // Open Output
  outFile.open(file_name + ".out");
  if (outFile) std::cerr << "File " << file_name << ".out" << " opened" << std::endl;
  else std::cerr << "File " << file_name << ".out" << " not opened" << std::endl;
}

FileHandling::~FileHandling () {
  std::cerr << "This is the destructor for FileHandling" << std::endl;
  // Close Files
  inFile.close();
  outFile.close();
}