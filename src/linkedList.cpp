#include "linkedList.hh"
#include <iostream>

linkedList::linkedList()
{
    head = new node;
    head->data = 0;
    head->next = NULL;
}

linkedList::linkedList(int val)
{
    head = new node;
    head->data = val;
    head->next = NULL;
}

linkedList::~linkedList()
{
    int i = 0;

    while(head != NULL){
        std::cout << head->data << std::endl;
        remove(i);
    }
}

int linkedList::append(int val)
{
    int len = 1;
    node* curr = head;
    node* add = new node;

    while(curr->next != NULL){
        curr = curr->next;
        len++;
    }

    curr->next = add;
    add->data = val;
    add->next = NULL;

    len += 1;

    return len;

}

int linkedList::prettyPrint()
{
    node* curr = head;
    int len = 0;

    while(curr != NULL){
        std::cout << curr->data << " --> ";
        curr = curr->next;
        len++;
    }
    std::cout << "NULL" << std::endl;

    return len;
}

int linkedList::remove(int index)
{
    node* curr = head;
    int len = 1;

    if(index == 0){
        head = head->next;
        delete curr;
        return len;
    }
    else{
        node* prev;
        for(int i = 0; i < index; i++){
            prev = curr;
            curr = curr->next;
            len++;
        }

        prev->next = curr->next;
        delete curr;
        
        return len-1;
    }

}