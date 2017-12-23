//
// Created by Mehmet on 23/07/2017.
//

#ifndef HW4_AVL_H
#define HW4_AVL_H

#include "Node.h"
#include <string>

using std::string;

typedef string ItemType;

class AVL {
public:
    AVL();
    ~AVL();
    void insert(ItemType newItem);
    void inorder();


private:
    // root pointer
    Node * root;
    bool firstInit;
    // rotations
    Node * rotateLeft(Node * nodePtr);
    Node * rotateRight(Node * nodePtr);
    Node * rotateRightLeft(Node * nodePtr);
    Node * rotateLeftRight(Node * nodePtr);
    // rotations end here...
    void inorderHelper(Node * rootPtr);
    void treeRebuild(Node * rootPtr);
    void insertHelper(ItemType new_item, Node  *& rootPtr);
    void destructorHelper(Node * rootPtr);
    int balance(Node * nodePtr);

};


#endif //HW4_AVL_H
