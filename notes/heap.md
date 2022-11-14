Heap
    - A variation on the BST where all the elements are smaller than its children
    - Insertion happens from top to bottom and left to right
    - If the element inserted is smaller than its parent, bubble upwards until it is
    - If root is deleted, insert the bottom right element and bubble it downwards

    - Implentation may happen with just an array
        - Left child index is 2k+1, and right child index is 2k+2