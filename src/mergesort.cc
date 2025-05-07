#include "mergesort.hh"

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

/*
function sort(L[1:n])
---
Input: A list L of n integers
Output: A list of then integers sorted in increasing order

 if n=1 then
    return L
 endif
 L1 = sort(L[1:n/2])
 L2 = sort(L[n/2:n])
 Merge L1 and L2 by considering the integers in L1 and L2 in order.
 return the resulting sorted list
*/
#include <algorithm>
std::vector<int> mergesort(std::vector<int> vec) {
    DUMMY_CODE(vec);
    return {};
}