#include "bst.hh"
#include <iostream>
using namespace std;

bst::bst()    
{
    root = nullptr;
}

bst::~bst()
{
    killTree(root);
}

void bst::killTree(treeNode* node)
{
    if(node != nullptr){
        killTree(node->left);
        killTree(node->right);
        delete node;
    }
}

void bst::insert(int val, treeNode* node)
{
    if(val <= node->data){
        if(node->left == nullptr){
            node->left = new treeNode;
            node->left->data = val;
            node->left->left = nullptr;
            node->left->right = nullptr;
        }
        else{
            insert(val, node->left);
        }
    }
    else{
        if(node->right == nullptr){
            node->right = new treeNode;
            node->right->data = val;
            node->right->left = nullptr;
            node->right->right = nullptr;
        }
        else{
            insert(val, node->right);
        }
    }
}

void bst::insert(int val) // Abstraction of overloaded insert function that conceals private root node
{
    if(root != nullptr)
        insert(val, root);
    else{
        root = new treeNode;
        root->data = val;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void bst::inOrder(treeNode* node)
{
    if(node != nullptr){
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void bst::inOrder() // Abstraction again!!
{
    inOrder(root);
    cout << endl;
}

void bst::preOrder(treeNode* node)
{
    if(node != nullptr){
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void bst::preOrder() // Abstraction again!!
{
    preOrder(root);
    cout << endl;
}

void bst::postOrder(treeNode* node)
{
    if(node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void bst::postOrder() // Abstraction again!!
{
    postOrder(root);
    cout << endl;
}