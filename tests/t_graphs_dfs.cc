#include "graphs/dfs.hh"
#include "utils/rng.hh"
#include "utils/test_helper.hh"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    try {
        { EXPECT_EQ(1, 1); }

    } catch (const std::exception &e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}
