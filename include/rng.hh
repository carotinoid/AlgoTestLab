#include <chrono>
#include <random>
#include <climits>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int randint(int L = INT_MIN, int R = INT_MAX) {
    std::uniform_int_distribution<int> uni(L, R);
    return uni(rng);
}
