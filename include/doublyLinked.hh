#ifndef doublyLinked_hh
#define doublyLinked_hh

struct NODE
{
    int data;
    NODE* next;
    NODE* prev;
};

typedef struct NODE node;

class doublyLinked {
    node* head;

    public:
    doublyLinked();
    doublyLinked(int val);
    ~doublyLinked();
    int append(int val);
    int remove(int index);
    int insert(int val, int index);
    int prettyPrint();
    
    doublyLinked reverse();
};

#endif