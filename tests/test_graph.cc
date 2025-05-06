#include "graph.hh"
#include <gtest/gtest.h>
#include <iostream>

TEST(GeneralGraphTest, GraphCreation) {
    Graph g(5);
    EXPECT_EQ(g.get_num_nodes(), 5);
}