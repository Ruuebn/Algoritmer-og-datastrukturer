#include <iostream>
#include <vector>

// Complexity: O(nlogn)

// Merge sort with a data type E, and a function C
template <typename E, typename C>
void mergeSort(std::vector<E>& S, const C& func) {
    typedef typename std::vector<E>::iterator Itor;
    size_t n = S.size();
    // If the length of the list is less than or equal to 1, list is already sorted: return
    if(n <= 1) return;

    // Split list into two smaller lists
    std::vector<E> S1, S2;

    // p doesn't necessarily need to be an iterator
    Itor p = S.begin();

    // Split S1 into one half, and S2 into the other half
    for(size_t i = 0; i < n / 2; ++i) S1.push_back(*p++);
    for(size_t i = n / 2; i < n; ++i) S2.push_back(*p++);

    // S is cleared for merge()
    S.clear();

    // Recursively call mergeSort() until all lists have length 2
    mergeSort(S1, func);
    mergeSort(S2, func);

    // merge S1 and S2 into S with the comparison function func
    merge(S1, S2, S, func);
}

// Merge two lists S1 and S2 into S
template <typename E, typename C>
void merge(std::vector<E>& S1, std::vector<E>& S2, std::vector<E>& S, const C& func) {
    typedef typename std::vector<E>::iterator Itor;
    Itor p1 = S1.begin();
    Itor p2 = S2.begin();
    // Compare the elements of S1 and S2
    // Note how p1 and p2 are able to iterate independently with this while loop -> advantage over a for loop
    while(p1 != S1.end() && p2 != S2.end()) {
        if(func(*p1, *p2)) {
            S.push_back(*p1++);
        } else {
            S.push_back(*p2++);
        }
    }
    // After comparison, push all sorted values
    while(p1 != S1.end()) S.push_back(*p1++);
    while(p2 != S2.end()) S.push_back(*p2++);
}

// Makes life easier
template <typename E>
void printList(std::vector<E> S) {
    for(auto e : S) std::cout << e << std::endl;
}

int main() {
    
    std::vector<int> arr {3, 7, 1, 9, 3, 7, 12345, 753, 74556, 234};

    // The second argument is a lambda function: a function without a name.
    // This lambda function returns a boolean: a < b.
    // You can pass in any type of function, as long as it returns a boolean.
    // This lambda function will result in an array sorted from the smallest integer to the largest
    // However, an array doesn't have to be sorted from smallest to largest, an array can be sorted whichever way you want
    mergeSort(arr, [](int a, int b) { return a < b; });
    // Finally, print the list
    printList(arr);

}
