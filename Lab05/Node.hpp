#ifndef EECS560_NODE_HPP
#define EECS560_NODE_HPP


class Node {
private:
    bool _tag;
    Node* _first;
    Node* _second;
    Node* _third;
    Node* _parent;
    int _key;
    int _minSecond;
    int _minThird;
public:
    /**
     * Creates interior Node
     */
    Node();

    /**
     * Creates leaf Node
     * @param value : key of Node
     */
    Node(int value);

    ~Node();

    friend bool operator<(const Node &left, const Node &right);
    friend bool operator==(const Node &left, const Node &right);
    friend bool operator!=(const Node &left, const Node &right);
    friend bool operator>(const Node &left, const Node &right);
    friend bool operator>=(const Node &left, const Node &right);
    friend bool operator<=(const Node &left, const Node &right);

    /**
     * Returns whether Node is leaf or not
     * @return true if leaf, false if not
     */
    bool IsLeaf();

    bool IsTwo();

    bool IsThree();

    int GetKey();

    void SetParent(Node* p);

    void SetFirst(Node *p);

    void SetSecond(Node *p);

    void SetThird(Node *p);

    void SetMinSecond(int value);

    void SetMinSecond(Node* n);

    void SetMinThird(int value);

    void SetMinThird(Node* n);

    int GetMinSecond();

    int GetMinThird();

    Node* GetParent();

    Node* GetFirst();

    Node* GetSecond();

    Node* GetThird();

    void Print(const std::string name);
};


#endif //EECS560_NODE_HPP
