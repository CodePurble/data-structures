#include "bst.h"
#include <iostream>

bst::bst()
{
    root = nullptr;
}

bst::~bst()
{
    if(root != nullptr)
        delete root;
}

bst::bst(bst& source)
{
    /* todo */    
}

void bst::addNode(int val)
{
    if(root != nullptr)
        root->insertLeaf(val);
    else{
        root = new treeNode(val);
    }
}

void bst::inOrder()
{
    root->inOrder();
    std::cout << std::endl;
}

void bst::preOrder()
{
    root->preOrder();
    std::cout << std::endl;
}

void bst::postOrder()
{
    root->postOrder();
    std::cout << std::endl;
}

bool bst::search(int key)
{
    return root->search(key);
}
