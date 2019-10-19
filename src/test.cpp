#include<iostream>
// #include "doublyLinked.hh"
#include "linkedList.hh"
using namespace std;

int main()
{
    linkedList l, l2;

    for(int i = 0; i < 3; i++){
        l.append(2*i);
        l2.append(i*i);
    }

    linkedList l3 = l;
    // linkedList l3;

    cout << "l is ";
    l.prettyPrint();
    cout << "l2 is ";
    l2.prettyPrint();
    cout << "l3 is ";
    l3.prettyPrint();
    
    l = l3 = l2;
    // // l3 = l;

    // l.assign(&l2);

    l.reverse();
    l2.reverse();
    l3.reverse();

    cout << "l is ";
    l.prettyPrint();
    cout << "l2 is ";
    l2.prettyPrint();
    cout << "l3 is ";
    l3.prettyPrint();

    return 0;
}