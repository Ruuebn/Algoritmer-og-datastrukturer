## Radix sort

Radix sort is to do digit by digit sort from LSD to MSD
    - Consider the digits in the 1's, 10's, 100's, up to 10^n's place
    - Sort the digits in this manner up until the largest 10^n number
    - Place items in a bucket as a subroutine
        - Example: 462, 273, 1465, 722, 383
        - First the 1's place
            2: 462, 722
            3: 273, 383
            5: 1465
            out: 462, 722, 273, 383, 1465
        - Then 10's place
            2: 722
            6: 462, 1465
            7: 273
            8: 383
            out: 722, 462, 1465, 273, 383
        - Then 100's place
            2: 273
            3: 383
            4: 462, 1465
            7: 722
            out: 273, 383, 462, 1465, 722
        - Then 1000's place:
            0: 273, 383, 462, 722
            1: 1465
            out: 273, 383, 462, 722, 1465
        - Note that we did not have to sort the contents of the buckets, it happened by itself

Bucket sort
    - Make buckets with an identifier for each item from your list
        - In the case of a list with integers, for example [1, 7, 3, 6, 4, 1, 4, 3]
            - These elements are put in a bucket
                1: 1, 1
                2:
                3: 3
                4: 4, 4
                5:
                6: 6
                7: 7
            - Then they are put in order back into the list: [1, 1, 3, 4, 4, 6, 7]
        - In the case of a list with floating point numbers, make buckets that encompass a range from one integer to the next
        - Example: [0.32, 0.76, 0.35, 0.34, 0.64, 0.65]
            - Put them in their buckets:
                [0.0-0.1):
                [0.1-0.2):
                [0.2-0.3):
                [0.3-0.4): .32, .35, .34
                ...
                [0.6-0.7): .64, .65
                [0.7-0.8): .76
            - When putting the list back together, sort each bucket, as the elements that were put in, were only put in sequential order, not sorted order
            - Then they are put back into the list: [0.32, 0.34, 0.35, 0.64, 0.65, 0.76]

Selection sort
    - Very simple to implement
    - Example list: [2, 8, 5, 3, 9, 4, 1]
    - Start at the beginning of the list, and keep track of the current minimum
    - We start at 2 [0], and iterate through the list until we find a smaller number. When we do, swap the zeroth place with the current minimum
        - This results in [1, 8, 5, 3, 9, 2]
    - Continue in this manner until the list is sorted
        [1, 8, 5, 3, 9, 2] -> swap [1] and [5] (swap 8 and 2)
        [1, 2, 5, 3, 9, 8] -> swap [2] and [3] (swap 5 and 3)
        [1, 2, 3, 5, 9, 8] -> do nothing, as the number is in the correct spot
        [1, 2, 3, 5, 9, 8] -> swap [4] and [5] (swap 9 and 8)
        [1, 2, 3, 5, 8, 9]
