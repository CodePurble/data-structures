#include <iostream>
#include "binaryTree.hh"

using namespace std;

int main()
{
    bNode* root = nullptr;

    root = insert(root, 4);
    root = insert(root, 5);

    preOrderTraversal(root);

    return 0;
}