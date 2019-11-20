#include "bst.hh"
#include <iostream>
using namespace std;

int main()
{
	bst tree;

	tree.addNode(5);
	tree.addNode(4);
	tree.addNode(3);
	tree.addNode(7);
	tree.addNode(6);

	tree.inOrder();
	// tree.postOrder();
	// tree.preOrder();


	if(tree.search(100))
		cout << "found\n";
	else
		cout << "not found\n";
	

    return 0;
}