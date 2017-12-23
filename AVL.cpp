//
// Created by Mehmet on 23/07/2017.
//

#include "AVL.h"
#include <iostream>

using std::cout;
using std::endl;


// default constructor
AVL::AVL() {
    root = NULL; // NULL
}

AVL::~AVL() {
    destructorHelper(root);
}

/**
 * Inorder&Inorder helper
 * Mainly for testing purposes
 */

void AVL::inorder() {
    inorderHelper(root);
}

void AVL::inorderHelper(Node * rootPtr) {
        if(rootPtr != NULL)
        {
            inorderHelper(rootPtr->left);
            cout << rootPtr->item << endl;
            inorderHelper(rootPtr->right);

        }
}

/**
 * insert&inserthelper
 */

void AVL::insert(ItemType newItem) {
    insertHelper(newItem, root);
}

void AVL::insertHelper(ItemType new_item, Node *& rootPtr) {
    if (rootPtr == NULL){
        rootPtr = new Node(new_item);
        rootPtr->calculateHeightDifference();
    }
    else {
        if (new_item < rootPtr->item){
            insertHelper(new_item, root->left);
            rootPtr->calculateHeightDifference();
            treeRebuild(rootPtr);
        }
        else{
            insertHelper(new_item, rootPtr->right);
            rootPtr->calculateHeightDifference();
            treeRebuild(rootPtr);
        }
    }
}


/**
 * Private functions
 */

// Since the book does not cover avl trees at all I had found a pseudo-code from stackoverflow
// therefore this function is mainly inspired by the mentioned source


/**
 * Rotations
 * They basically work like swap functions, but you have to manipulate pointer objects instead of copying them
 * This was the greatest way to learn how rotations work: https://www.cise.ufl.edu/~nemo/cop3530/AVL-Tree-Rotations.pdf
 */

Node* AVL::rotateLeft(Node * nodePtr) {
    Node * tmp = nodePtr->right;
    nodePtr->right = tmp->left;
    tmp->left = nodePtr;
    tmp->calculateHeightDifference();
    return tmp;
}

Node* AVL::rotateRight(Node * nodePtr) {
    Node * tmp = nodePtr->left;
    nodePtr->left = tmp->right;
    tmp->right = nodePtr;
    tmp->calculateHeightDifference();
    return tmp;
}

Node* AVL::rotateLeftRight(Node * nodePtr) {
    // left rotation
    Node * tmp = nodePtr->left;
    nodePtr->left = rotateLeft(tmp);
    // right rotation
    return rotateRight(nodePtr);
}

Node* AVL::rotateRightLeft(Node * nodePtr) {
    // right rotation
    Node * tmp = nodePtr->right;
    nodePtr->right = rotateRight(tmp);
    // left rotation
    return rotateLeft(nodePtr);
}


/**
 * Auxilary functions
 */

void AVL::destructorHelper(Node *rootPtr) {
    destructorHelper(rootPtr->left);
    destructorHelper(rootPtr->right);
    delete rootPtr;
}

// this is very much like the fifth exam question
int AVL::balance(Node * nodePtr) {
    int leftHeight = 0;
    int rightHeight = 0;

    leftHeight = 1 + balance(nodePtr->left);
    rightHeight = 1 + balance(nodePtr->right);

    return leftHeight - rightHeight;
}