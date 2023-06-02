// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <stdexcept>


template<typename T>
class BST {
    struct Node {
        Node() : left(nullptr), right(nullptr), count(0) {}
        T value;
        int count;
        Node *left, *right;
    };
    Node* root;
    Node* emptyNode;

    Node* addNode(Node* root, const T& value);
    int searchTree(Node* root, const T& value);
    void delTree(Node* root);
    int heightTree(const Node* root) const;
    void printTree(const Node* root) const;

 public:
    BST();
    ~BST();
    void add(const T& value);
    int search(const T& value);
    int depth();
    void print();
};

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, const T& value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
    } else if (root->value == value) {
        root->count++;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    }
    return root;
}

template<typename T>
int BST<T>::searchTree(Node* root, const T& value) {
    if (!root)
        return 0;
    if (root->value == value)
        return root->count;
    if (root->value > value)
        return searchTree(root->left, value);
    if (root->value < value)
        return searchTree(root->right, value);
    throw std::runtime_error("Not found value <...>");
}

template<typename T>
void BST<T>::delTree(Node* root) {
    if (!root)
        return;
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = nullptr;
}

template<typename T>
int BST<T>::heightTree(const Node* root) const {
    if (!root)
        return 0;
    int hleft = heightTree(root->left);
    int hright = heightTree(root->right);
    return (hleft > hright ? hleft : hright) + 1;
}

template<typename T>
void BST<T>::printTree(const Node* root) const {
    if (!root)
        return;
    printTree(root->left);
    std::cout << root->value << "(x" << root->count << ")\t";
    printTree(root->right);
}

template<typename T>
BST<T>::BST() : root(nullptr), emptyNode(new Node) {}

template<typename T>
BST<T>::~BST() {
    delTree(root);
    delete emptyNode;
}

template<typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value);
}

template<typename T>
int BST<T>::search(const T& value) {
    return searchTree(root, value);
}

template<typename T>
int BST<T>::depth() {
    return heightTree(root) - 1;
}

template<typename T>
void BST<T>::print() {
    printTree(root);
}

#endif  // INCLUDE_BST_H_
