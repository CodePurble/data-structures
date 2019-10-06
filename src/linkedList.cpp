#include "linkedList.hh"
#include <iostream>

linkedList::linkedList()
{
    // head = new node;
    // head->data = 0;
    // head->next = NULL;
    head = NULL;
}

linkedList::linkedList(int val)
{
    head = new node;
    head->data = val;
    head->next = NULL;
}

linkedList::linkedList(linkedList& source)
{
    this->assign(source);
    std::cout << "Copy constructor" << std::endl;
}

linkedList::~linkedList()
{
    destroy();
}

void linkedList::destroy()
{
    int i = 0;

    while(head != NULL){
        remove(i);
    }

    std::cout << "Destruction!!!" << std::endl;
}

linkedList* linkedList::clone()
{
    linkedList* listClone = NULL;
    node* curr = head;
    
    while(curr != NULL){
        listClone->append(curr->data);
        curr = curr->next;
    }

    return listClone;
}

void linkedList::assign(linkedList source)
{
    linkedList* old = this;
    head = (source.clone())->head;
    old->destroy();
}

int linkedList::append(int val)
{
    int len = 1;
    node* curr = head;

    if(curr == NULL){
        head = new node;
        head->data = val;
        head->next = NULL;
        return len;
    }
    else{
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

int linkedList::insert(int val, int index)
{
    int l = 1;
    node* ins = new node;
    node* curr = head;
    node* prev;
    
    ins->data = val;

    if(index == 0){
        head = ins;
        head->next = curr;
        return l+1;
    }
    else{
    for(int i = 0; i < index; i++){
        prev = curr;
        curr = curr->next;
        l++;
    }

    prev->next = ins;
    ins->next = curr;

    return l+1;
    }
}

void linkedList::reverse()
{
    node* curr = head->next;
    node* prev = head;
    node* nxt = curr->next;
    prev->next = NULL;

    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = nxt;

        if(nxt != NULL)
            nxt = nxt->next;
    }

    head = prev;
}

linkedList linkedList::operator=(linkedList source)
{
    this->assign(source);
    
    return *this;
}
