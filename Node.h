//
// Created by Mehmet on 23/07/2017.
//

#ifndef HW4_NODE_H
#define HW4_NODE_H

#include <string>

using std::string;

typedef string ItemType;

class Node {
public:
    Node(ItemType newItem);
    ItemType getItem();
    Node * getLeftPtr();
    Node * getRightPtr();
    int getHeight();
    void calculateHeightDifference();
private:
    ItemType item;
    int height;
    Node * left;
    Node * right;

    friend class AVL;

};


#endif //HW4_NODE_H
