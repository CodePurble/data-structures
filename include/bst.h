#ifndef bst_h
#define bst_h
#include "treeNode.h"

class bst
{
    treeNode* root;
    void killTree();

    public:
        bst();
        bst(bst& source);
        ~bst();
        void addNode(int val);
        void inOrder();
        void preOrder();
        void postOrder();
        bool search(int key);
};

#endif
