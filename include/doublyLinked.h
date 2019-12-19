#ifndef doublyLinked_h
#define doublyLinked_h

struct NODE
{
    int data;
    NODE* next;
    NODE* prev;
};

typedef struct NODE node;

class doublyLinked {
    private:
        node* head;
        int len;

        doublyLinked* clone();
        void clean();

    public:
        doublyLinked();
        doublyLinked(int val);
        doublyLinked(doublyLinked& source);
        ~doublyLinked();

        void append(int val);
        void remove(int index);
        void insert(int val, int index);
        void replace(int val, int index);
        void assign(doublyLinked* source);
        void prettyPrint();
        int getLength();
        doublyLinked* reverse();

        doublyLinked& operator=(doublyLinked source);
    
};

#endif
