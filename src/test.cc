#include "bst.h"
#include <iostream>
using namespace std;

int main()
{
	int key = 1;
	bst tree;

	tree.addNode(5);
	tree.addNode(4);
	tree.addNode(3);
	tree.addNode(7);
	tree.addNode(6);

	tree.inOrder();
	// tree.postOrder();
	// tree.preOrder();


	if(tree.search(key))
		cout << key << " found\n";
	else
		cout << key << " not found\n";
	

    return 0;
}
