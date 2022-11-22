## AVL Tree

AVL
    - Self-balancing tree
        - A BST, but it has the special property of the height difference between left and right children always being <= 1 (left - right) <= 1
    - If the tree is empty, height is -1
    - If the tree contains one element (only the root), height is 0
    - If the tree has more nodes than one, height is defined recursively
        - H(n) = max(H(n.left), H(n.right)) + 1
    
    - B(n) = H(n.left) - H(n.right)
        - This describes the balance of the AVL tree. The difference of height between left and right children should always be less than or equal to 1
            - |B(n)| <= 1
    - If B(n) > 1, rotations need to happen
        - If the tree is left-heavy, right rotate
            - or left-right rotation if the identifier is a triangle
        - If the tree is right-heavy, left rotate
            - or right-left rotation if the identifier is a triangle
