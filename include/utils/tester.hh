#include <iostream>
#include <vector>

namespace tester {

template <typename T>
class vector : public std::vector<T> {
  private:
    int tcount = 0;

  public:
    using std::vector<T>::vector;
    T &operator[](size_t index) {
        tcount++;
        return std::vector<T>::operator[](index);
    }
    T &at(int idx) {
        tcount++;
        return std::vector<T>::at(idx);
    }
    int num_called() const { return tcount; }
};

}  // namespace tester