#include<iostream>
// #include "doublyLinked.hh"
#include "linkedList.hh"
using namespace std;

int main()
{
    linkedList l;

    for(int i = 0; i < 5; i++){
        l.append(2*i);
    }

    l.prettyPrint();
    l.assign(l.reverse());
    l.prettyPrint();

    return 0;
}