#include "bst.hh"
#include <iostream>
using namespace std;

int main()
{
    bst tree;

	tree.insert(10);
	tree.insert(6);
	tree.insert(14);
	tree.insert(5);
	tree.insert(8);
	tree.insert(11);
	tree.insert(18);

    tree.inOrder();
    tree.preOrder();
    tree.postOrder();

    return 0;
}