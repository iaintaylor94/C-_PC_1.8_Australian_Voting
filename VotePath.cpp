#include "VotePath.h"

void Vote_path::printPath(std::vector<int> p) {
  int i = 0;
  for (auto it = p.begin(); it != p.end(); ++it, i++) 
    std::cout << std::setw(2) << *it << " ";
  for ( ; i < MAX_NUM_CANDIDATES; i++) 
    std::cout << "   " ;
}

void Vote_path::printVote (Vote* v, std::vector<int> p, int nc) {
  printPath(v->path);
  std::cout << std::setw(5) << v->num_votes << std::endl;
  
  for (int i = 0; i < nc; i++) {
    if (v->branches[i] != nullptr) {
      printVote (v->branches[i], p, nc);
    }
  }
}

void Vote_path::printTree () {
  std::cout << "                                                     Vote_Path Votes" << std::endl;
  std::cout << "-------------------------------------------------------------- -----" << std::endl; 
  for (int i = 0; i < num_candidates; i++) {
    printVote(root.branches[i], path, num_candidates);
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
  //printPath(v->path);
  //std::cout << std::endl;
  
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