#ifndef bst_hh
#define bst_hh

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;
};

class bst
{
    treeNode* root;
    void killTree(treeNode* node);
    void insert(int val, treeNode* node);
    void inOrder(treeNode* node);
    void postOrder(treeNode* node);
    void preOrder(treeNode* node);

    public:
        bst();
        ~bst();
        void insert(int val);
        void inOrder();
        void preOrder();
        void postOrder();
};

#endif