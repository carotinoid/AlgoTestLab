#include "divide_and_conquer/binary_search.hh"

#include <algorithm>

template <typename... Targs>
void DUMMY_CODE(Targs &&.../* unused */) {}

using std::vector;

/*
function binary_search(L[1:n], k)
---
Input: A list L of n integers and integer k
Output: A position (index) of k in L or -1 if k is not in L
*/
int binary_search(vector<int> vec, int k) {
    // DUMMY_CODE(vec, k);
    // return{};
    auto it = std::lower_bound(vec.begin(), vec.end(), k);
    if (*it == k) {
        return it - vec.begin();
    } else {
        return -1;
    }
}

/*
function lower_bound(L[1:n], k)
---
Input: A list L of n integers and integer k
Output: The position (index) of the first element in L that is not less than k
Note. There is std::lower_bound in C++ STL, algorithm header. Your job is implement it.
*/
int lower_bound(vector<int> vec, int k) {
    DUMMY_CODE(vec, k);
    return -1;
}

/*
function upper_bound(L[1:n], k)
---
Input: A list L of n integers and integer k
Output: The position (index) of the first element in L that is greater than k
Note. There is std::upper_bound in C++ STL, algorithm header. Your job is implement it.
*/
int upper_bound(vector<int> vec, int k) {
    DUMMY_CODE(vec, k);
    return -1;
}