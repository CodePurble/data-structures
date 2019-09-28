#ifndef linkedList_hh
#define linkedList_hh

class linkedList {
    struct node
    {
        int data;
        node* next;
    } *head;

    public:
    linkedList();
    linkedList(int val);
    ~linkedList();
    int append(int val);
    int remove(int index);
    int insert(int index);
    int prettyPrint();
};

#endif