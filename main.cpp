#include <iostream>
#include "AVL.h"

int main() {
    AVL tree;

    std::cout << "FUCK " << std::endl;

    tree.insert("a");
    tree.insert("b");
    tree.insert("x");
    tree.insert("d");
    tree.insert("e");
    tree.insert("f");
    tree.insert("g");
    tree.insert("h");
    tree.insert("j");
    tree.insert("k");
    tree.insert("l");
    tree.insert("m");
    tree.insert("n");
    tree.insert("c");
    tree.insert("q");
    tree.insert("o");
    tree.insert("v");

    tree.inorder();
}