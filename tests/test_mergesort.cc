#include "divide_and_conquer/mergesort.hh"
#include "utils/rng.hh"

#include <gtest/gtest.h>

TEST(Mergesort, OneElem) {
    std::vector<int> v = {100};
    std::vector<int> res = mergesort(v);
    EXPECT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], 100);
}

TEST(Mergesort, TwoElem) {
    std::vector<int> v = {randint(), randint()};
    if (v[0] < v[1])
        std::swap(v[0], v[1]);
    std::vector<int> res = mergesort(v);
    EXPECT_EQ(res.size(), 2);
    EXPECT_LE(res[0], res[1]);
}

TEST(Mergesort, TenElem) {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(randint());
    std::vector<int> res = mergesort(v);
    EXPECT_EQ(res.size(), 10);
    for (int i = 0; i < 9; i++)
        EXPECT_LE(res[i], res[i + 1]);
}

#include <algorithm>
TEST(Mergesort, TenElemWithStdSort) {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(randint());
    std::vector<int> res = mergesort(v);
    std::sort(v.begin(), v.end());
    EXPECT_EQ(v, res);
}

TEST(Mergesort, ManyElemWithStdSort) {
    std::vector<int> v;
    for (int i = 0; i < 20000; i++)
        v.push_back(randint());
    std::vector<int> res = mergesort(v);
    std::sort(v.begin(), v.end());
    EXPECT_EQ(v, res);
}