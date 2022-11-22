## Sorting

Merge-sort is divided into three parts
    - Divide
        - If the input S is smaller than a certain threshold, solve it directly, else, divide the set into two subsets S1 and S2 of length n/2 where n is the size of the list
    - Recursion
        - Recursively sort sequences S1 and S2
    - Conquer
        - Merge S1 and S2 into sorted S

Quick-sort is also divided into three parts, but all the word is done before recursive calls
    - Divide
        - If the list S has at least two elements, select an element x from S, x is called the pivot. Common practice is that x is the last element in S
            - L storing elements in S less than x
            - E storing elements in S equal to x
            - G storing elements in S greater than x
    - Recur
        - Recursively sort sequences L and G
    - Conquer
        - Finally, put all elements back into S with L first, E second, and G last
