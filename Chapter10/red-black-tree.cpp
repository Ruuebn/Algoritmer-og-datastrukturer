#include <iostream>

enum Color {RED, BLACK};

template <typename T>
class Node {
private:
    Color col;
protected:
    typedef typename E::Key K;
    typedef typename E::Value V;
    Color color() { return col; }
    bool isRed() { return col == RED; }
    bool isBlack() { return col == BLACK; }
    void setColor(Color c) { col = c; }
public:
    Node(const K& k == K(), const V& v = V()) : E(k, v), col(BLACK) {}
    friend class NodeTree<T>;

};

template <typename T>
class NodeTree : public SearchTree<Node<T>> {
public:
    typedef Node<T> Node;
    typedef typename SearchTree<Node>::Iterator Iterator;
protected:
    typedef typename Node::Key K;
    typedef typename Node::Value V;
    typedef SearchTree<Node> ST;
    typedef typename ST::TPos TPos;
public:

    NodeTree();
    Iterator insert(const K& k, const V& x) {
        TPos v = inserter(k, x);
        if(v == ST::root()) {
            setBlack(v);
        }
        else {
            setRed(v);
            remedyDoubleRed(v);
        }
        return Iterator(v);
    }
    void erase(const K& k) throw(NonexistentElement);
    void erase(const Iterator& p);

protected:
    void remedyDoubleRed(const TPos& z);
    void remedyDoubleBlack(const TPos& r);
};

