#include<iostream>
#include "doublyLinked.hh"
#include "linkedList.hh"
using namespace std;

int main()
{
    linkedList l;
    

    for(int i = 1; i < 5; i++){
        l.append(i);
    }

    l.prettyPrint();



    return 0;
}