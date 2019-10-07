#include "doublyLinked.hh"
#include <iostream>

doublyLinked::doublyLinked()
{
    // head = new node;
    // head->data = 0;
    // head->next = NULL;
    // head->prev = NULL;
    head = NULL;
}

doublyLinked::doublyLinked(int val)
{
    head = new node;
    head->data = val;
    head->next = NULL;
    head->prev = NULL;
}

doublyLinked::~doublyLinked()
{
    while(head != NULL){
        remove(0);
    }
}

int doublyLinked::append(int val)
{
    int len = 1;
    node* curr = head;
    node* add = new node;

    if(curr == NULL){
        head = new node;
        head->data = val;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }

        curr->next = add;
        add->prev = curr;
        add->data = val;
        add->next = NULL;

        len += 1;

    }
    return len;


}

int doublyLinked::prettyPrint()
{
    node* curr = head;
    int len = 0;

    while(curr != NULL){
        if(curr->prev == NULL)
            std::cout << "NULL <-- ";
        if(curr->next == NULL)
            std::cout << curr->data << " --> ";
        else
            std::cout << curr->data << " <--> ";

        curr = curr->next;
        len++;
    }
    std::cout << "NULL" << std::endl;

    return len;
}

int doublyLinked::remove(int index)
{
    node* curr = head;
    int len = 1;

    if(index == 0){
        if(head->next == NULL){
            delete head;
            head = NULL;
            return 0;
        }
        else{
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        return len;
        }
    }
    else{
        for(int i = 0; i < index; i++){
            curr = curr->next;
            len++;
        }

        curr->prev->next = curr->next;
        if(curr->next != NULL)
            curr->next->prev = curr->prev;
        delete curr;
        
        return len-1;
    }

}

int doublyLinked::insert(int val, int index)
{
    int l = 1;
    node* ins = new node;
    node* curr = head;
    
    ins->data = val;

    if(index == 0){
        head = ins;
        head->prev = NULL;
        head->next = curr;
        curr->prev = head;
        return l+1;
    }
    else{
        for(int i = 0; i < index; i++){
            curr = curr->next;
            l++;
    }
        curr->prev->next = ins;
        ins->prev = curr->prev;
        curr->prev = ins;
        ins->next = curr;

    return l+1;
    }
}

doublyLinked doublyLinked::reverse()
{
    doublyLinked rev;

    node* curr = head;

    while(curr->next != NULL){
        rev.append(curr->data);
        curr = curr->next;
    }
        rev.append(curr->data);
        // rev.prettyPrint();

    node* revCurr = rev.head;
    while(curr != NULL){
        revCurr->data = curr->data;
        std::cout << curr->data << std::endl;
        revCurr = revCurr->next;
        curr = curr->prev;
    }
        rev.prettyPrint();

    return rev;
}