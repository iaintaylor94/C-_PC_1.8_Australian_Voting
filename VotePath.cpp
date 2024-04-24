#include "VotePath.h"

void Vote_path::printPath(std::vector<int> p) {
  for (auto it = p.begin(); it != p.end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;
}

void Vote_path::printVote (Vote* v, std::vector<int> p, int nc) {
  printPath(v->path);
  for (int i = 0; i < nc; i++) {
    if (v->branches[i] != nullptr) {
      printVote (v->branches[i], p, nc);
    }
  }
}

void Vote_path::printTree (int nc) {
  for (int i = 0; i < nc; i++) {
    printVote(root.branches[i], path, nc);
  }
}

bool Vote_path::inPath (std::vector<int> p, int i) {
  for (auto it = p.begin(); it != p.end(); it++) {
    if (*it == i) return true;
  }
  return false;
}

void Vote_path::initVote (Vote* v, std::vector<int> p, int nc) {
  
  v->path = p;
  printPath(v->path);
  
  for (int i = 0; i < num_candidates; i++) {  
    if (inPath(p, i)) v->branches.push_back(nullptr);
    else {
      v->branches.push_back(new Vote);
      p.push_back (i);
      initVote (v->branches[i], p, nc);
      p.pop_back();
    }
  }
}

void Vote_path::createTree (int nc) {
  num_candidates = nc;
  for (int i = 0; i < nc; i++) {
    root.branches.push_back(new Vote);
    path.push_back (i);
    initVote(root.branches[i], path, nc);
    path.pop_back();
  }
}