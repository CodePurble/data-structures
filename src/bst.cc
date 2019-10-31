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

void bst::killTree(treeNode* rootNode)
{
    if(rootNode != nullptr){
        killTree(rootNode->left);
        killTree(rootNode->right);
        delete rootNode;
    }
}

void bst::insert(int val, treeNode* rootNode)
{
    if(val <= rootNode->data){
        if(rootNode->left == nullptr){
            rootNode->left = new treeNode;
            rootNode->left->data = val;
            rootNode->left->left = nullptr;
            rootNode->left->right = nullptr;
        }
        else{
            insert(val, rootNode->left);
        }
    }
    else{
        if(rootNode->right == nullptr){
            rootNode->right = new treeNode;
            rootNode->right->data = val;
            rootNode->right->left = nullptr;
            rootNode->right->right = nullptr;
        }
        else{
            insert(val, rootNode->right);
        }
    }
}

void bst::insert(int val) // Abstraction of overloaded insert function that conceals private root rootNode
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

void bst::inOrder(treeNode* rootNode)
{
    if(rootNode != nullptr){
        inOrder(rootNode->left);
        cout << rootNode->data << " ";
        inOrder(rootNode->right);
    }
}

void bst::inOrder() // Abstraction again!!
{
    inOrder(root);
    cout << endl;
}

void bst::preOrder(treeNode* rootNode)
{
    if(rootNode != nullptr){
        cout << rootNode->data << " ";
        preOrder(rootNode->left);
        preOrder(rootNode->right);
    }
}

void bst::preOrder() // Abstraction again!!
{
    preOrder(root);
    cout << endl;
}

void bst::postOrder(treeNode* rootNode)
{
    if(rootNode != nullptr){
        postOrder(rootNode->left);
        postOrder(rootNode->right);
        cout << rootNode->data << " ";
    }
}

void bst::postOrder() // Abstraction again!!
{
    postOrder(root);
    cout << endl;
}