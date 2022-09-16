#include <iostream>
#include <vector>

// Complexity: O(n^2)

// Bubble sort with datatype E and function C
template <class E, class C>
void bubbleSort(std::vector<E>& S, const C& comp) {
    size_t s = S.size();
    // If the size is 1 or less, array is already sorted, return and exit function
    if(s <= 1) return;

    while (s > 1) {
        for (size_t n = 0; n < s - 1; ++n) {
            // Temporary variable in order to swap values
            E tmp = S[n];
            // Call function comp(a, b) and return boolean
            if (comp(S[n], S[n + 1])) {
                // Swap
                S[n] = S[n + 1];
                S[n + 1] = tmp;
            }
        }
        // Decrement s for each iteration, it is not necessary to compare values already sorted
        --s;
    }
}

int main() {
    std::vector<int> arr {4, 76, 1, 456, 390, 1000};
    // Read MergeSort.cpp @ lines 66- to learn more about the second argument in the function call
    // The comparison operator here is different from the one in MergeSort.cpp
    // Because the comp function is different
    bubbleSort(arr, [](int a, int b) { return a > b; });
}
