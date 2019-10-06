#ifndef linkedList_hh
#define linkedList_hh

struct NODE
{
    int data;
    NODE* next;
};

typedef NODE node;

class linkedList {
    private:
    node* head;
    linkedList* clone();
    void assign(linkedList source);
    void destroy();

    public:
    linkedList();
    linkedList(int val);
    linkedList(linkedList& list2); // Copy constructor
    ~linkedList();
    int append(int val);
    int remove(int index);
    int insert(int val, int index);
    int prettyPrint();
    void reverse();
    linkedList operator=(linkedList list2);
};

#endif