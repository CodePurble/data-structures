#ifndef bst_hh
#define bst_hh
#include "treeNode.hh"

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
};

#endif