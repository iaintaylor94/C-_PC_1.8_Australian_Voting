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
  for (int i = 1; i < num_candidates; i++) {
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
  num_candidates = nc + 1;
  
  root.branches.push_back(nullptr); // Disable "0" for root
  path.push_back(0); // Disable "0" for tree
  
  for (int i = 1; i < num_candidates; i++) {
    root.branches.push_back(new Vote);
    path.push_back (i);
    initVote(root.branches[i], path, num_candidates);
    path.pop_back();
  }
}

void Vote_path::deleteVote (Vote* v) {
  for (int i = 0; i < num_candidates; i++) {
    if (v->branches[i] != nullptr) {
      deleteVote(v->branches[i]);
      delete v->branches[i];
    }
  }
}
void Vote_path::deleteTree (void) {
  for (int i = 0; i < num_candidates; i++) {
    deleteVote(root.branches[i]);
  }
}

void Vote_path::updateVotePath (Vote* v, std::queue<int> vp) {
  vp.pop();

  if (vp.empty()) return;
  
  v->branches[vp.front()]->num_votes++;
  updateVotePath (v->branches[vp.front()], vp);
}
void Vote_path::addVP(std::queue<int> vp) {
  root.branches[vp.front()]->num_votes++;
  updateVotePath(root.branches[vp.front()], vp);
}

void Vote_path::eliminateVote (Vote* v, int ID) {
  if (v->isEliminated) {
    for (int i = 1; i < num_candidates; i++) {
      if (v->branches[i] == nullptr) continue;
      else eliminateVote(v->branches[i], ID);
    }
  }
  else {
    v->isEliminated = true;
    // candidate ID is last element in the v->path
    secondPreference[v->path.back()] += v->num_votes;
    
  }
}
std::vector<int> Vote_path::eliminateLoser (int ID) {
  secondPreference.clear();
  secondPreference.resize(MAX_NUM_CANDIDATES + 1); // Candidates start at 1
  secondPreference[0] = 0;
  eliminateVote(root.branches[ID], ID);
  return secondPreference;
}