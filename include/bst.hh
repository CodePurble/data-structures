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
    void killTree(treeNode* rootNode);
    void insert(int val, treeNode* rootNode);
    void inOrder(treeNode* rootNode);
    void postOrder(treeNode* rootNode);
    void preOrder(treeNode* rootNode);

    public:
        bst();
        ~bst();
        void insert(int val);
        void inOrder();
        void preOrder();
        void postOrder();
};

#endif