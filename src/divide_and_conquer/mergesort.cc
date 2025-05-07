#include "divide_and_conquer/mergesort.hh"

template <typename... Targs>
void DUMMY_CODE(Targs &&.../* unused */) {}

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
    if (vec.size() == 1)
        return vec;
    if (vec.size() == 2) {
        if (vec[0] > vec[1])
            std::swap(vec[0], vec[1]);
        return vec;
    }
    std::vector<int> L(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> R(vec.begin() + vec.size() / 2, vec.end());
    L = mergesort(L);
    R = mergesort(R);
    std::vector<int> res{};
    int Lsize = L.size(), Rsize = R.size(), l = 0, r = 0;
    while (l < Lsize or r < Rsize) {
        if (l >= Lsize)
            res.push_back(R[r++]);
        else if (r >= Rsize)
            res.push_back(L[l++]);
        else {
            if (L[l] > R[r])
                res.push_back(R[r++]);
            else
                res.push_back(L[l++]);
        }
    }
    return res;
}