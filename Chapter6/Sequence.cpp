#include <iostream>
#include <deque>

template <typename T>
using iterator = typename std::deque<T>::iterator;

// Sequence class inherits from std::deque
template <typename T>
class Sequence : public std::deque<T> {
public:

    // Returns iterator for a certain index
    // dot notation cannot be used for pointers ("this" is a pointer)
    iterator<T> at_index(size_t i) {
        return this->begin() + i;
    }    

    // Returns index for a certain iterator
    // alternative if you reaaaaaally want to use dot notation for pointers
    size_t index_of(iterator<T> it) {
        return it - (*this).begin();
    }
};

// Different implementation of bubbleSort using all for loops
// And implementation from Sequence class
template <typename E, typename C>
void bubbleSort(Sequence<E>& seq, const C& comp) {
    // If sequence is empty or has one element, already sorted
    if(seq.size() <= 1) return;
    for(size_t i = 0; i < seq.size() - 1; ++i) {
        // Loop containing variable j will decrease by 1 each iteration of i
        for(size_t j = 0; j < seq.size() - 1 - i; ++j) {
            auto x = seq.at_index(j);
            auto y = seq.at_index(j + 1);

            // Don't know if seq.index_of() is required, or if just *x and *y could be used in std::swap
            if(comp(*x, *y)) std::swap(seq[seq.index_of(x)], seq[seq.index_of(y)]);
        }
    }
}

// Test out code
int main() {
    Sequence<int> seq;
    seq.push_back(45);
    seq.push_back(93);
    seq.push_back(12);
    seq.push_back(7);

    bubbleSort(seq, [](int a, int b) { return a > b; });
}
