//
// Created by Mehmet on 23/07/2017.
//

#include "Node.h"
#include <stdlib.h>

using std::max;


Node::Node(ItemType newItem) {
    item = newItem;
    height = 1;
    left = NULL;
    right = NULL;
}

ItemType Node::getItem() { return item; }
int Node::getHeight() { return height; }
Node * Node::getLeftPtr() { return left; }
Node * Node::getRightPtr() { return right; }

void Node::calculateHeightDifference() {
    int leftHeight, rightHeight;

    if (left) {
        leftHeight = left->height;
    }

    if (right) {
        rightHeight = right->height;
    }

    height = 1 + abs(max(leftHeight, rightHeight));
}