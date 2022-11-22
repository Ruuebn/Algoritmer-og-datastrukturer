### (2, 4)-trees

(2, 4)-tree is not a binary tree
    - Three types of nodes
        - 2-nodes with 1 key and max 2 children
        - 3-nodes with 2 keys and max 3 children
        - 4-nodes with 3 keys and max 4 children
    - The keys in a node is sorted in ascending order
    - All children that are smaller than the smallest key is in the left subtree
    - All children that are bigger than the smallest, but smaller than the second smallest is in a subtree between them
        - etc...
    
    - Insertion
        - When we insert a value, we search downwards like a BST, and place it in the external node where it fits
        - If this node is a 4-node that becomes a 5-node, we now violate a condition
        - When this happens, bubble the middle element up to its parent keeping the sorted manner
            - If the parent node then becomes a 5-node, continue bubbling upwards
            - If the root node becomes a 5-node, make a new root node with the middle element
    
    - Deletion
        - When we delete an element x from a (2, 4)-tree:
            - The largest element in the subtree left for x replace x
            - If we receive an invalid 1-node with no keys, we must:
                - If the 1-node has a closest sibling with more than one key we can transfer
                    - Move the key from the sibling to the parent, and a key from the parent down to the 1-node
                - If the 1-node does not have a closest sibling with more than one key, we fuse
                    - Fuse together 1-node with a sibling and move a key down from the parent

B-tree
    - A B-tree is a generalisation of an (a, b)-tree
        - (2, M)-tree = M-tree
        - An M-tree can at least have 2 children, but at most M children
        - Node that M > 2 because a 2-tree is in essence only a linked list
