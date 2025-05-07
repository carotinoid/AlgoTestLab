#include <exception>
#include <string>
#include <stdexcept>
#include <vector>

using std::to_string;

template<typename T>
std::string to_string(const std::vector<T>& vec) {
    std::string result = "[";
    for (const auto& elem : vec) {
        result += to_string(elem) + ", ";
    }
    if (!vec.empty()) {
        result.pop_back();
        result.pop_back();
    }
    result += "]";
    return result;
}

template<typename T>
void EXPECT_EQ(const T& expected, const T& actual) {
    if (expected != actual) {
        throw std::runtime_error("Expected equal: " + to_string(expected) + ", Actual: " + to_string(actual));
    }
}
template<typename T>
void EXPECT_NE(const T& expected, const T& actual) {
    if (expected == actual) {
        throw std::runtime_error("Expected not equal: " + to_string(expected) + ", Actual: " + to_string(actual));
    }
}
template<typename T>
void EXPECT_LT(const T& expected, const T& actual) {
    if (expected >= actual) {
        throw std::runtime_error("Expected less than: " + to_string(expected) + ", Actual: " + to_string(actual));
    }
}
template<typename T>
void EXPECT_LE(const T& expected, const T& actual) {
    if (expected > actual) {
        throw std::runtime_error("Expected less than or equal: " + to_string(expected) + ", Actual: " + to_string(actual));
    }
}
template<typename T>
void EXPECT_GT(const T& expected, const T& actual) {
    if (expected <= actual) {
        throw std::runtime_error("Expected greater than: " + to_string(expected) + ", Actual: " + to_string(actual));
    }
}
template<typename T>
void EXPECT_GE(const T& expected, const T& actual) {
    if (expected < actual) {
        throw std::runtime_error("Expected greater than or equal: " + to_string(expected) + ", Actual: " + to_string(actual));
    }
}
template<typename T>
void EXPECT_TRUE(const T& condition) {
    if (!condition) {
        throw std::runtime_error("Expected true, but got false");
    }
}
template<typename T>
void EXPECT_FALSE(const T& condition) {
    if (condition) {
        throw std::runtime_error("Expected false, but got true");
    }
}
template<typename T>
void EXPECT_THROW(const T& expression, const std::exception& expected_exception) {
    bool flag = false;
    try {
        expression;
    } catch (const std::exception& e) {
        flag = true;
    }
    if (!flag) {
        throw std::runtime_error("Expected exception: " + std::string(typeid(expected_exception).name()));
    }
}