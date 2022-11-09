## Memory management

To implement any data structure, we need to use memory
Memory is a sequence of memory words, consisting of 4, 8, or 16 bytes depending on the compouter
    - Numbered from 0 to N - 1

Memory
    - Internal fragmentation
    - External fragmentation
    - Best-fit algorithm
    - First-fit algorithm
    - Next-fit algorithm
    - Worst-fit algorithm

    - Garbage collection
        - mark-sweep algorithm
            - When an object is created, its mark is set to 0 (false)
            - In the Mark Phase, we set the marked bit for all the reachable objects to 1 (true)
                - To perform this, perform a graph traversal (depth first search)
                - If you can reach a node N from the root, then N is reachable
                    - If not, N is considered garbage
                - Mark all reachable objects
            - Root is a variable that refers to an object, and is directly accessible by a local variable

            - Sweep phase
                - Sweeps unreachable objects, clears heap memory
                - If a memory block is not marked, free it from memory, object is neither reachable or accessible
    
    - External memory and caching
        - Memory hierarchy, from slowest to fastest (biggest to smallest)
            - External memory, internal memory, cache, registers, cpu
        - Blocking
            - Motivated by spacial locality

        - Caching algorithms
            - Cache memory
            - Fully associative cache
            - Page replacement algorithms
                - FIFO
                - LRU
                - Random

    - External searching and B-trees
        - External memory searching is the process of accessing a task or sorting data from external storage (outisde main memory)
        - (a, b) trees are multi-way search trees 
            - Balanced search tree
                - Where a and b are positive integers such that 2 <= a <= (b+1)/2
                    - Each internal node except root has at least a and atmost b children, and the root has at most b children
                    - All paths from the root to the external nodes have the same length/depth
        - B-trees
            - Self-balancing search tree in which each node an contain more than one kay and can have more than two children
            - Generalised form of the BST
            - Known as a height-balanced m-way tree

            - Every internal node should have at least m/2 child nodes
            - If a non-leaf node has n children, then it must contain n - 1 keys or values
            - All leaf nodes should appear at the same level of the tree

