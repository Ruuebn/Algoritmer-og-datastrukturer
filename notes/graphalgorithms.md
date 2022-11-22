## Graph algorithms, kruskal's, prim's, dijkstra's

A graph
    - Consists of edges and vertices
    - A node can have as many edges and neighboring nodes as it wants
    - A path is a sequence of nodes with edges between them: a-b-e
    - A cycle is a path that leads to the starting nodes: a-b-e-a
    - A graph is connected if there exists a path from a node to every other node, if not, it is disconnected
    - A tree is a connected acyclical graph
    - A connected graph's spanning tree is a tree that contains every node and is a tree

    Graph traversal:
        - Depth-first
            - Go an unmarked path and bring a rope
            - Mark all edges from a cross section when you pass them
            - Turn and follow the rope if you come to a marked edge
            - Go back by following the rope if you come to a section where all edges are marked
        
            - To program this:
                - Mark all visited nodes
                - Recursively visit all unvisited neighboring nodes
        - Breadth-first
            - Put all unmarked neighboring nodes in a queue to-be-visited, and mark them as we visit
            - Get the first node in the queue to visit
    - A graph can have weighted edges, meaning that there's a cost going from one node to another
    Prim's algorithm:
        - Pick an arbitrary node
        - Find the edge with the lowest weight
        - Connect these two nodes, and repeat the second step without making a cyclical graph, checking all edges
        - If two or more edges contain the lowest cost and does not form a cyclical graph, pick a random one (for implementation, it's easiest to pick the first one you find)
        - Return the minimum spanning tree formed from this algorithm (MST)
    Kruskal's algorithm:
        - Find the lowest cost edge that does not make a cycle, and add it to the MST. Continue until you have n - 1 edges for a graph with n nodes
    Dijkstra's algorithm:
        - Set the distance of the starting node to 0, and all other neighboring nodes to inf
        - Mark the starting node as visited, and all others as unvisited
        - Take the edges of the present node, and update the distance to all other neighboring nodes
        - Mark the present node as visited, and set the unvisited node with the least distance as the present node
        - Repeat step 3, stop when all nodes have been visited
