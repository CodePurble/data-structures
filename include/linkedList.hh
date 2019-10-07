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
    int len;

    linkedList* clone();
    void clean();

    public:
    linkedList();
    linkedList(int val);
    linkedList(linkedList& source); // Copy constructor
    ~linkedList();

    void assign(linkedList* source);
    void append(int val);
    void remove(int index);
    void insert(int val, int index);
    void replace(int val, int index);
    int getLength();
    void reverse();
    void prettyPrint();

    linkedList& operator=(linkedList list2); //Returning a reference is key!!
};

#endif