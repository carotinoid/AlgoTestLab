#include "divide_and_conquer/mergesort.hh"
#include "utils/rng.hh"
#include "utils/test_helper.hh"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    try {
        {
            std::vector<int> vec;
            for (int i = 0; i < 100; ++i) {
                vec.push_back(randint(0, 100));
            }
            std::vector<int> res = mergesort(vec);
            std::sort(vec.begin(), vec.end());
            EXPECT_EQ(res, vec);
        }

    } catch (const std::exception &e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}
