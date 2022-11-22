## Red-black tree

A type of (2, 4) tree
    - A node is either red or black
    - The root and leaves are black
    - If a node is red, the its children are black
    - All paths from a nide to its NULL descendants contain the same number of black nodes

    - Rotation
        - alters the structure in order to decrease the height of the tree
        - larger subtrees up, smaller subtrees down
        - does not affect the order of the elements
            - left-rotate
                - rotating left on a root makes its right child its parent, and the right child's left subtree its right subtree
                        5*
                       / \
                      2   10'
                         /  \
                        8^   12
                       / \
                      6   9

                    goes to

                          10'
                         /  \
                        5*   12
                       / \
                      2   8^
                         / \
                        6   9

                    in other words
                        x*
                       / \
                      u   y'
                         / \
                        z^  v
                    ->
                        y'
                       / \
                      x*  v
                     / \
                    u   z^
                    where x < z < y 
                    
            - right rotate
                - rotating right on a root makes its left child its parent, and the left child's right subtree its left subtree
                        10*
                       /  \
                      5'   12
                     /  \
                    2    8^
                        / \
                       6   9
                    
                    goes to
                        5'
                       /  \
                      2    10*
                          /  \
                         8^   12
                        / \
                       6   9

                    in other words
                        x*
                       / \
                      y'  u
                     / \
                    v   z^

                    ->
                        y'
                       / \
                      v   x*
                         / \
                        z^  u
                    where x > z > y
        - take note of that rotating does conserve the properties of a tree. even when rotating, all the rules of a binary tree is followed

    - Insertion
        - color the node red when inserting
        - recolor and rotate nodes to fix violation
        - 4 scenarios
            - Z = root
            - Z.uncle = red
            - Z.uncle = black(triangle)
            - Z.uncle = black(line)

            - Z = root
                - just recolor Z to black
            - Z.uncle = red
                - recolor Z.parent, Z.uncle, Z.grandparent (switch from black to red and red to black)
            - Z.uncle = black(triangle) - triangle means when Z is a left child, and its parent is a right child (of Z's grandparent - it kind of looks like a triangle)
                                        - or opposite -> when Z is a right child, and its parent is a left child
                - rotate Z.parent
                    - If A is Z.parent, then Z takes A's space. if Z is left child of A, A becomes Z's right child. and opposite
            - Z.uncle = black(line) - line means the identifier looks like a line. Z is a left child, and its parent is also a left child
                                    - or Z is a right child, and its parent is also a right child
                - rotate Z.grandparent
                    - If B is Z.grandparent, and A is Z.parent, they are all right children
                        - B becomes A's left child, A's left subtree becomes B's right subtree, and Z stays A's right child
                        - Recolor after rotation
        
        - Insertion example
            - Insert 15
                - All inserted nodes are red, but since 15 is the root, color it black
            - Insert 5
                - This insertion does not result in a violation
            - Insert 1
                - Violation, 5 is a red node, and 1 is a red node as well as being the left child of 5. The identifier becomes a line
                - Third case. We rotate 1's grandparent in the opposite direction of 1 (to the right)
                - 5 is now the root, its left child 1, right child 15
                - Recolor the parent and the grandparent. 5=black,15=red,1=red
            
                        
