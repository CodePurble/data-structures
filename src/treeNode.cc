#include "treeNode.h"
#include <iostream>

treeNode::treeNode(int val)
{
    data = val;
    left = right = nullptr;
}

treeNode::treeNode(treeNode& source)
{
    data = source.data;
    left = right = nullptr;

    if(source.left != nullptr)
        insertLeaf(source.left->data);
    if(source.right != nullptr)
        insertLeaf(source.right->data);
}

treeNode::~treeNode()
{
    deleteNode();
}

void treeNode::deleteNode()
{
    if(left != nullptr)
        delete left;
    if(right != nullptr)
        delete right;
}

void treeNode::insertLeaf(int val)
{
    if(val < data){
        if(left == nullptr)
            left = new treeNode(val);
        else
            left->insertLeaf(val);
    }
    else{
        if(right == nullptr)
            right = new treeNode(val);
        else
            right->insertLeaf(val);
    }
}

void treeNode::inOrder()
{
    if(left != nullptr)
        left->inOrder();
    std::cout << data << " ";
    if(right != nullptr)
        right->inOrder();
}

void treeNode::preOrder()
{
    std::cout << data << " ";
    if(left != nullptr)
        left->inOrder();
    if(right != nullptr)
        right->inOrder();
}

void treeNode::postOrder()
{
    if(left != nullptr)
        left->inOrder();
    if(right != nullptr)
        right->inOrder();
    std::cout << data << " ";
}

bool treeNode::search(int key)
{

    if(key == data)
        return true;
    else if(key < data){
        if(left != nullptr)
            left->search(key);
        else
            return false;
    }
    else{
        if(right != nullptr)
            right->search(key);
        else
            return false;
    }
}
