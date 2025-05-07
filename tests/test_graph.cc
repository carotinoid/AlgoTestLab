#include "graphs/graph.hh"

#include <gtest/gtest.h>

TEST(GeneralGraphTest, GraphCreation) {
    Graph g(5);
    EXPECT_EQ(g.get_num_nodes(), 5);
}