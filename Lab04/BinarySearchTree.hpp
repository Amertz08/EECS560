#ifndef EECS560_BINARYSEARCHTREE_HPP
#define EECS560_BINARYSEARCHTREE_HPP

#include "Node.hpp"

class BinarySearchTree {
private:
    Node* root;

public:
    /**
     * Basic Binary Search Tree class
     */
    BinarySearchTree();
    ~BinarySearchTree();

    /**
     * Destructor helper that deletes nodes
     * @param target : node to possible delete
     */
    void _delete(Node* target);

    /**
     * Checks if BST is empty or not
     * @return true if empty. false if not
     */
    bool empty();

    /**
     * Inserts value into BST
     * @param value
     */
    void insert(int value);

    /**
     * Helper function that recursively inserts value
     * @param target : target node ptr
     * @param newNode : new node to insert
     */
    void _insert(Node* target, Node* newNode);

    /**
     * Returns ptr to node if value found
     * @param value
     * @return ptr to node of first instance of value or nullptr if not found
     */
    Node* find(int value);

    /**
     * Recursive helper function for find
     * @param target
     * @param value
     * @return
     */
    Node* _find(Node* target, int value);

    /**
     * Returns pointer to min value in BST
     * @return ptr to min value or nullptr
     */
    Node* findMin();

    /**
     * Recursive helper function for findMin
     * @param target
     * @return ptr to min value or nullptr
     */
    Node* _findMin(Node* target);

    /**
     * Returns pointer to max value
     * @return ptr to max value or nullptr
     */
    Node* findMax();

    /**
     * Recursive helper function for findMax
     * @param target
     * @return ptr to max value or nullptr
     */
    Node* _findMax(Node* target);

    /**
     * Deletes min value from BST
     */
    void deleteMin();

    /**
     * Deletes max value from BST
     */
    void deleteMax();

    /**
     * Prints BST in pre-order
     */
    void preOrder();

    /**
     * Recursive helper function for preOrder
     * @param target
     */
    void _preOrder(Node* target);

    /**
     * Prints BST in order
     */
    void inOrder();

    /**
     * Recursive helper function for inOrder
     * @param target
     */
    void _inOrder(Node* target);

    /**
     * Prints BST in post-order
     */
    void postOrder();

    /**
     * Recursive helper function for postOrder
     * @param target
     */
    void _postOrder(Node* target);

    /**
     * Deletes first instance of specific value from BST
     * @param value
     */
    void deleteValue(int value);
};


#endif //EECS560_BINARYSEARCHTREE_HPP
