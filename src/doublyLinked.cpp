#include "doublyLinked.hh"
#include <iostream>

doublyLinked::doublyLinked()
{
    // head = new node;
    // head->data = 0;
    // head->next = nullptr;
    // head->prev = nullptr;
    head = nullptr;
<<<<<<< HEAD
=======
    len = 0;
>>>>>>> master
}

doublyLinked::doublyLinked(int val)
{
    head = new node;
    head->data = val;
    head->next = nullptr;
    head->prev = nullptr;
<<<<<<< HEAD
=======

    len = 1;
}

doublyLinked::doublyLinked(doublyLinked& source)
{
    this->head = nullptr;
    this->assign(&source);
>>>>>>> master
}

doublyLinked::~doublyLinked()
{
<<<<<<< HEAD
=======
    clean();
}

doublyLinked* doublyLinked::clone()
{
    doublyLinked* listClone = new doublyLinked;
    node* curr = head;

    while(curr != nullptr){
        listClone->append(curr->data);
        curr = curr->next;
    }

    return listClone;
}

void doublyLinked::assign(doublyLinked* source)
{
    node* srcCurr = source->head;
    this->clean();
    
    while(srcCurr != nullptr){
        this->append(srcCurr->data);
        srcCurr = srcCurr->next;
    }
}

void doublyLinked::clean()
{
>>>>>>> master
    while(head != nullptr){
        remove(0);
    }
}

void doublyLinked::append(int val)
{
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
        }

        curr->next = add;
        add->prev = curr;
        add->data = val;
        add->next = nullptr;


    }
    len++;
}

void doublyLinked::prettyPrint()
{
    node* curr = head;

    while(curr != nullptr){
        if(curr->prev == nullptr)
            std::cout << "nullptr <-- ";
        if(curr->next == nullptr)
            std::cout << curr->data << " --> ";
        else
            std::cout << curr->data << " <--> ";

        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;

}

void doublyLinked::remove(int index)
{
    node* curr = head;

<<<<<<< HEAD
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
=======
    if(index < 0 || index >= len){
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    else{
        if(index == 0){
            head = head->next;
            if(head != nullptr){
                delete head->prev;
                head->prev = nullptr;
            }
            else{
                delete head;
            }
        }
        else{
            for(int i = 0; i < index; i++)
                curr = curr->next;

            curr->prev->next = curr->next;
            if(curr->next != nullptr)
                curr->next->prev = curr->prev;
            delete curr;
>>>>>>> master
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
            head->prev = nullptr;
            head->next = curr;
            if(curr != nullptr)
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

<<<<<<< HEAD
        curr->prev->next = curr->next;
        if(curr->next != nullptr)
            curr->next->prev = curr->prev;
        delete curr;
        
        return len-1;
=======
doublyLinked* doublyLinked::reverse() // Non mutating reverse; Must be used like this -> list1.assign(list2.reverse())
{
    doublyLinked* selfClone = this->clone();

    node* pre = selfClone->head;
    node* curr = selfClone->head->next;
    node* nxt = curr->next;
    pre->next = nullptr;

    while(curr != nullptr){
        curr->next = pre;
        curr->prev = nxt;
        pre = curr;
        curr = nxt;

        if(nxt != nullptr)
            nxt = nxt->next;
>>>>>>> master
    }

    selfClone->head = pre;

    return selfClone;
}

void doublyLinked::replace(int val, int index)
{
<<<<<<< HEAD
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
=======
    if(index < 0 || index >= len){
        std::cout << "Index out of bounds!!" << std::endl;
        return;
>>>>>>> master
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
<<<<<<< HEAD
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
=======
    this->assign(&source);
    return *this;
}
>>>>>>> master

int doublyLinked::getLength()
{
    return len;
}