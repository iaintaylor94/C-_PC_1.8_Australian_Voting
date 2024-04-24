#ifndef VOTE_H
#define VOTE_H

#include <vector>

struct Vote {
  std::vector <int> path;
  std::vector <Vote*> branches;
};


#endif