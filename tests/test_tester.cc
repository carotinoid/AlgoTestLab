#include "utils/rng.hh"
#include "utils/tester.hh"

#include <gtest/gtest.h>

//////////// Tester::vector ////////////
TEST(TesterVector, CountNumCalled) {
    tester::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec.num_called(), 0);
    int a = vec[2];
    a = vec[2];
    EXPECT_EQ(vec.num_called(), 2);
    a = vec[2];
    EXPECT_EQ(vec.num_called(), 3);
}

TEST(TesterVector, BasicMethodsofStdVector) {
    tester::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(randint());
    EXPECT_EQ(vec.size(), 10);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 9);
    vec.emplace_back(200);
    EXPECT_EQ(vec.size(), 10);
    tester::vector<int> vec2(vec);
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec2.size(), 10);
}
