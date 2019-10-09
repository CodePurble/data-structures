#include "doublyLinked.hh"
#include <iostream>

doublyLinked::doublyLinked()
{
    // head = new node;
    // head->data = 0;
    // head->next = NULL;
    // head->prev = NULL;
    head = NULL;
    len = 0;
}

doublyLinked::doublyLinked(int val)
{
    head = new node;
    head->data = val;
    head->next = NULL;
    head->prev = NULL;

    len = 1;
}

doublyLinked::doublyLinked(doublyLinked& source)
{
    this->head = NULL;
    this->assign(&source);
}

doublyLinked::~doublyLinked()
{
    clean();
}

doublyLinked* doublyLinked::clone()
{
    doublyLinked* listClone = new doublyLinked;
    node* curr = head;

    while(curr != NULL){
        listClone->append(curr->data);
        curr = curr->next;
    }

    return listClone;
}

void doublyLinked::assign(doublyLinked* source)
{
    node* srcCurr = source->head;
    this->clean();
    
    while(srcCurr != NULL){
        this->append(srcCurr->data);
        srcCurr = srcCurr->next;
    }
}

void doublyLinked::clean()
{
    while(head != NULL){
        remove(0);
    }
}

void doublyLinked::append(int val)
{
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
        }

        curr->next = add;
        add->prev = curr;
        add->data = val;
        add->next = NULL;


    }
    len++;
}

void doublyLinked::prettyPrint()
{
    node* curr = head;

    while(curr != NULL){
        if(curr->prev == NULL)
            std::cout << "NULL <-- ";
        if(curr->next == NULL)
            std::cout << curr->data << " --> ";
        else
            std::cout << curr->data << " <--> ";

        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;

}

void doublyLinked::remove(int index)
{
    node* curr = head;

    if(index < 0 || index >= len){
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    else{
        if(index == 0){
            head = head->next;
            if(head != NULL){
                delete head->prev;
                head->prev = NULL;
            }
            else{
                delete head;
            }
        }
        else{
            for(int i = 0; i < index; i++)
                curr = curr->next;

            curr->prev->next = curr->next;
            if(curr->next != NULL)
                curr->next->prev = curr->prev;
            delete curr;
        }

        len--;
    }

}

void doublyLinked::insert(int val, int index)
{
    if(index < 0 || index >= len){
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    else{
        node* ins = new node;
        node* curr = head;
        
        ins->data = val;

        if(index == 0){
            head = ins;
            head->prev = NULL;
            head->next = curr;
            if(curr != NULL)
                curr->prev = head;
        }
        else{
            for(int i = 0; i < index; i++){
                curr = curr->next;
        }
            curr->prev->next = ins;
            ins->prev = curr->prev;
            curr->prev = ins;
            ins->next = curr;
        }
        len++;
    }    
}

doublyLinked* doublyLinked::reverse() // Non mutating reverse; Must be used like this -> list1.assign(list2.reverse())
{
    doublyLinked* selfClone = this->clone();

    node* pre = selfClone->head;
    node* curr = selfClone->head->next;
    node* nxt = curr->next;
    pre->next = NULL;

    while(curr != NULL){
        curr->next = pre;
        curr->prev = nxt;
        pre = curr;
        curr = nxt;

        if(nxt != NULL)
            nxt = nxt->next;
    }

    selfClone->head = pre;

    return selfClone;
}

void doublyLinked::replace(int val, int index)
{
    if(index < 0 || index >= len){
        std::cout << "Index out of bounds!!" << std::endl;
        return;
    }
    else{
        node* curr = head;

        for(int i = 0; i < index; i++)
            curr = curr->next;

        curr->data = val;
    }    
}

doublyLinked& doublyLinked::operator=(doublyLinked source)
{
    this->assign(&source);
    return *this;
}

int doublyLinked::getLength()
{
    return len;
}