#ifndef BINARY_SEARCH_HH
#define BINARY_SEARCH_HH

#include <vector>

int binary_search(std::vector<int> vec, int k);
int lower_bound(std::vector<int> vec, int k);
int upper_bound(std::vector<int> vec, int k);

#endif  // BINARY_SEARCH_HH