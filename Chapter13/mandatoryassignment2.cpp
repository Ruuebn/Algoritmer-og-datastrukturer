#include <iostream>
#include <vector>

// In order to make Edge class aware of some class Node
class Node;

class Edge {
private:
    int weight;
    Node* root;
    Node* neighbor;
public:
    Edge(int w, Node* r, Node* n) : weight{ w }, root{ r }, neighbor{ n } {}

	Node* getRoot() { return root; }
	Node* getNeighbor() { return neighbor; }
	int   getWeight() { return weight; }
};

class Node {
private:
    int name;
	std::vector<Edge*> edges;
public:
    Node(int n) : name{ n } {}

	// Deletes edgepointers associated with the Node class
	~Node() {
		for (Edge* e : edges) delete e;
	}

	// Makes edge
	void makeEdge(int w, Node* neighbor) {
		edges.push_back(new Edge(w, this, neighbor));
	}

	void removeEdge(size_t idx, Node* target) {
		// Remove edges at neighbors first connecting to target node
		Node* neighbor = (*(edges.begin() + idx))->getNeighbor();

		for (size_t i = 0; i < neighbor->getEdges().size(); ++i) {
			// Checks if neighbor of neighbor is target node
			if (target == neighbor->getEdgeAt(i)->getNeighbor()) {
				// After edge at neighbor node has been removed
				// return to jump out of recursive function call
				neighbor->removeEdge(i, target);
				return;
			}
		}

		// Erase edge at idx
		edges.erase(edges.begin() + idx);
	}

	// Get functions
	std::vector<Node*> getNeighbors() {
		std::vector<Node*> neighbors;
		for (auto it = edges.begin(); it != edges.end(); it++) {
			neighbors.push_back((*it)->getNeighbor());
		}
		return neighbors;
	}
	int				   getName() { return name; }
	std::vector<Edge*> getEdges() { return edges; }
	Edge*			   getEdgeAt(size_t idx) { return edges[idx]; }
};

class Graph {
private:
    std::vector<Node*> nodes;
public:
	~Graph() {
		for (Node* n : nodes) delete n;
	}

	// Adds a node to graph
	void addNode(Node* n) {
		nodes.push_back(n);
	}

	// When adding edge, a edge is placed in the root Node and its neighboring node
	// making the edge bidirectional
	void addEdge(int w, Node* root, Node* neighbor) {
		root->makeEdge(w, neighbor);
		neighbor->makeEdge(w, root);
	}

	void removeNode(size_t idx) {
		// First remove all edges from root node and its neighboring nodes
		for (size_t i = 0; i < nodes[idx]->getNeighbors().size(); i++) {
			nodes[idx]->removeEdge(i, nodes[idx]);
		}

		// Then remove node
		delete nodes[idx];
		nodes.erase(nodes.begin() + idx);
	}
	
	void removeEdge(size_t idx, size_t e_idx) {
		// Calls Node's removeEdge(), not Graph's removeEdge()
		nodes[idx]->removeEdge(e_idx, nodes[idx]);
	}

	// Get functions
	Node*			   getNodeAt(size_t idx) { return nodes[idx]; }
	std::vector<Node*> getNodes() { return nodes; }
	std::vector<Edge*> getEdges() {
		std::vector<Edge*> allEdges;
		for (auto n : getNodes()) {
			for (auto e : n->getEdges()) {
				allEdges.push_back(e);
			}
		}
		return allEdges;
	}

	// Auxiliary function
	void printGraphEdges() {
		for (auto n : getEdges()) {
			std::cout << n->getRoot()->getName() << " connected to " << n->getNeighbor()->getName() << " with weight " << n->getWeight() << std::endl;
		}
	}
};

// Driver code
int main() {
	Graph g;

	// Add nodes to graph
    auto nodeList = { 1, 2, 3, 4, 5, 6, 7 };
	for (auto n : nodeList) {
		g.addNode(new Node(n));
	}

	// Add edges to graph connecting nodes
	int edgeList[][3] = {{4, 0, 1}, // A to B, weight 4
						 {4, 0, 4}, // A to E, weight 4
						 {2, 0, 3}, // A to D, weight 2
						 {5, 1, 2}, // B to C, weight 5
						 {1, 1, 3}, // B to D, weight 1
						 {4, 2, 5}, // C to F, weight 4
						 {3, 3, 4}, // D to E, weight 3
						 {5, 4, 5}, // E to F, weight 5
						 {1, 5, 6}  // F to G, weight 1
	};
	for (auto edge : edgeList) {
		g.addEdge(edge[0], g.getNodeAt(edge[1]), g.getNodeAt(edge[2]));
	}

	g.printGraphEdges();

	// Remove node at index 0 (Node A), its edges, and its neighbors edges
	// connecting to it from Graph
	g.removeNode(0);
	std::cout << std::endl;

	g.printGraphEdges();
	
}
