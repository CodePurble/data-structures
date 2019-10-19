#include "doublyLinked.hh"
#include <iostream>

doublyLinked::doublyLinked()
{
    // head = new node;
    // head->data = 0;
    // head->next = nullptr;
    // head->prev = nullptr;
    head = nullptr;
}

doublyLinked::doublyLinked(int val)
{
    head = new node;
    head->data = val;
    head->next = nullptr;
    head->prev = nullptr;
}

doublyLinked::~doublyLinked()
{
    while(head != nullptr){
        remove(0);
    }
}

int doublyLinked::append(int val)
{
    int len = 1;
    node* curr = head;
    node* add = new node;

    if(curr == nullptr){
        head = new node;
        head->data = val;
        head->next = nullptr;
        head->prev = nullptr;
    }
    else{
        while(curr->next != nullptr){
            curr = curr->next;
            len++;
        }

        curr->next = add;
        add->prev = curr;
        add->data = val;
        add->next = nullptr;

        len += 1;

    }
    return len;


}

int doublyLinked::prettyPrint()
{
    node* curr = head;
    int len = 0;

    while(curr != nullptr){
        if(curr->prev == nullptr)
            std::cout << "nullptr <-- ";
        if(curr->next == nullptr)
            std::cout << curr->data << " --> ";
        else
            std::cout << curr->data << " <--> ";

        curr = curr->next;
        len++;
    }
    std::cout << "nullptr" << std::endl;

    return len;
}

int doublyLinked::remove(int index)
{
    node* curr = head;
    int len = 1;

    if(index == 0){
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return 0;
        }
        else{
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        return len;
        }
    }
    else{
        for(int i = 0; i < index; i++){
            curr = curr->next;
            len++;
        }

        curr->prev->next = curr->next;
        if(curr->next != nullptr)
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
        head->prev = nullptr;
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

    while(curr->next != nullptr){
        rev.append(curr->data);
        curr = curr->next;
    }
        rev.append(curr->data);
        // rev.prettyPrint();

    node* revCurr = rev.head;
    while(curr != nullptr){
        revCurr->data = curr->data;
        std::cout << curr->data << std::endl;
        revCurr = revCurr->next;
        curr = curr->prev;
    }
        rev.prettyPrint();

    return rev;
}