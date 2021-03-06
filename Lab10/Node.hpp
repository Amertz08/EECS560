#ifndef EECS560_NODE_HPP
#define EECS560_NODE_HPP


class Node {
private:
    int value;
    Node* parent;
    Node* left;
    Node* right;

    /**
     * Helper function that calculates node's rank
     * @param target : Node that is being looked at
     * @param rank : on going rank calculation
     * @return rank of the node
     */
    int _rank(Node* target, int rank);
public:
    /**
     * Node class for Binary search tree
     * @param value : Node value
     */
    explicit Node(int value);
    ~Node();
    friend bool operator<(const Node &n1, const Node &n2);
    friend bool operator==(const Node &n1, const Node &n2);
    friend bool operator!=(const Node &n1, const Node &n2);
    friend bool operator>(const Node &n1, const Node &n2);
    friend bool operator>=(const Node &n1, const Node &n2);
    friend bool operator<=(const Node &n1, const Node &n2);

    /**
     * Get parent pointer
     * @return Node ptr to parent
     */
    Node* getParent();

    /**
     * Get node value
     * @return
     */
    int getValue();

    /**
     * Get left node
     * @return Node ptr to left node
     */
    Node* getLeft();

    /**
     * Get right node
     * @return Node ptr to right node
     */
    Node* getRight();

    /**
     * Set value for node
     * @param value
     */
    void setValue(int value);

    /**
     * Set parent pointer
     * @param n
     */
    void setParent(Node* n);

    /**
     * Set left Node ptr
     * @param n
     */
    void setLeft(Node* n);

    /**
     * Set right Node ptr
     * @param n
     */
    void setRight(Node* n);

    /**
     * Finds rank of node
     * @return
     */
    int rank();
};


#endif //EECS560_NODE_HPP
