#ifndef treeNode_hh
#define treeNode_hh

class treeNode
{
    int data;
    treeNode* left;
    treeNode* right;

    public:
        treeNode(int val);
        treeNode(treeNode& source);
        ~treeNode();
        void deleteNode();
        void insertLeaf(int val);
        void inOrder();
        void preOrder();
        void postOrder();
        bool search(int key);
};

#endif
