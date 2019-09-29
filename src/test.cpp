#include<iostream>
#include "linkedList.hh"
using namespace std;

int main()
{
    linkedList l;

    for(int i = 1; i < 5; i++){
        l.append(i);
    }

    l.prettyPrint();

    l.insert(3232, 0);
    l.prettyPrint();


    return 0;
}