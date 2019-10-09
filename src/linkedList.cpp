#include "linkedList.hh"
#include <iostream>

linkedList::linkedList()
{
    // head = new node;
    // head->data = 0;
    // head->next = NULL;
    head = NULL;
    len = 0;
}

linkedList::linkedList(int val)
{
    head = new node;
    head->data = val;
    head->next = NULL;
    
    len = 1;
}

linkedList::linkedList(linkedList& source) // Copy constructor (called during initialisations)
{
    this->head = NULL;
    this->assign(&source);
}

linkedList::~linkedList()
{
    clean();
}

void linkedList::clean() // "Cleans" list of all its nodes
{
    while(head != NULL){
        remove(0);
    }
}

linkedList* linkedList::clone() // Create identical copy of calling list, returns its head
{
    linkedList* listClone = new linkedList;
    node* curr = head;
    
    while(curr != NULL){
        listClone->append(curr->data);
        curr = curr->next;
    }

    return listClone;
}

void linkedList::assign(linkedList* source) // Copies "source" list into calling list object
{
    node* srcCurr = source->head;
    this->clean();

    while(srcCurr != NULL){
        this->append(srcCurr->data);
        srcCurr = srcCurr->next;
    }
}   
/*Non cohesive, spaghetti implementation of assign() method*/
/*
    node* curr = head;
    int i = 0;
        if(i < len){
            this->replace(srcCurr->data, i);
            srcCurr = srcCurr->next;
            i++;
        }
        else{
            while(srcCurr != NULL){
                this->append(srcCurr->data);
                srcCurr = srcCurr->next;
            }
        }
    }

    if(source->len < len){
        for(int j = 0; j < i; j++)
            curr = curr->next;

        while(curr->next != NULL){
            remove(this->getLength()-1);
        }
        remove(this->getLength()-1);
    }
*/

/*
List traversal

node* curr = head;

while(curr->next != NULL){
    curr = curr->next;
}
*/
void linkedList::append(int val)
{
    if(head == NULL){
        head = new node;
        head->data = val;
        head->next = NULL;
    }
    else{
        node* add = new node;
        node* curr = head;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = add;
        add->data = val;
        add->next = NULL;


    }
    len++;

}

void linkedList::prettyPrint()
{
    node* curr = head;

    while(curr != NULL){
        std::cout << curr->data << " --> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

void linkedList::remove(int index)
{
    node* curr = head;

    if(index < 0 || index >= len){
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    else{
        if(index == 0){
            head = head->next;
            delete curr;
        }
        else{
            node* prev;
            for(int i = 0; i < index; i++){
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            delete curr;
            
        }
        len--;
    }
}

void linkedList::insert(int val, int index)
{

    if(index < 0 || index >= len){
        std::cout << "Index out of bounds!!" << std::endl;
        return;
    }
    else{
        node* ins = new node;
        node* curr = head;
        node* prev;
        
        ins->data = val;

        if(index == 0){
            head = ins;
            head->next = curr;
        }
        else{
        for(int i = 0; i < index; i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = ins;
        ins->next = curr;

        }
        len++;
    }
}

linkedList* linkedList::reverse() // Non mutating reverse; Must be used like this -> list1.assign(list2.reverse())
{
    linkedList* selfClone = this->clone();
    node* curr = selfClone->head->next;
    node* prev = selfClone->head;
    node* nxt = curr->next;
    prev->next = NULL;

    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = nxt;

        if(nxt != NULL)
            nxt = nxt->next;
    }

    selfClone->head = prev;
    return selfClone;
}

void linkedList::replace(int val, int index) // In place substitution of data of node 
{

    if(index < 0 || index > len-1)
        std::cout << "Index out of bounds!!!"  << std::endl;
    else{
        node* curr = head;

        for(int i = 0; i < index; i++){
            curr = curr->next;
        }
        
        if(curr != NULL){
            curr->data = val;
        }
    }
}

int linkedList::getLength()
{
    return len;
}

linkedList& linkedList::operator=(linkedList source)
{
    this->assign(&source);

    return *this;
}
