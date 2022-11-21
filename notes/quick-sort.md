## Quick Sort

Quick sort
    - choose a pivot (typically middle of the list, or median of three)
    - swap the pivot with the last element
    - find the first item that is larger than the pivot from the start of the list (left item)
    - find the first item that is smaller than the pivot starting from the end of the list (right item)
        - swap these two
    - repeat the process
        - stop when the index of the left item is greater than the index of the right item
            - when this condition is met, find the left item and swap it with the pivot
    - now that the pivot is in the correct spot, recurse for the items that are greater than the pivot, and the ones that are less

    - example:
        [2, 6, 5, *3, 8, 7, 1, **0] - *3 is pivot, **0 swap pivot with this one
        [2, 6, 5, 0, 8, 7, 1, 3] - find the first item that is greater than the pivot from the start, and the first one that is smaller from the pivot index
        [2, *6, 5, 0, 8, 7, *1, 3] - swap these items
        [2, 1, *5, *0, 8, 7, 6, 3] - repeat steps
        [2, 1, 0, 5, 8, 7, 6, 3] - when index of left item is larger than index of right item, swap the pivot and the left item
        [2, 1, 0, 3, 8, 7, 6, 5] - from the pivot, recurse right and left

            [2, *1, 0]
            [2, 0, 1]
            [0, 2, 1]
            [0, 1, 2]

            [8, 7, 6, 5]
            [8, 5, 6, 7]
            [6, 5, 8, 7]
            [6, 5, 7, 8] - recurse to the left
                [6, 5]
                [5, 6]
            [5, 6, 7, 8] - now merge

        [0, 1, 2, 3, 5, 6, 7, 8] - done

    

