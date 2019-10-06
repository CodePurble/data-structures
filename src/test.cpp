#include<iostream>
// #include "doublyLinked.hh"
#include "linkedList.hh"
using namespace std;

int main()
{
    linkedList l, l2;
    

    for(int i = 1; i < 5; i++){
        l.append(i);
        l2.append(i*i);
    }

    l.prettyPrint();
    l2.prettyPrint();
    cout << endl;

    l2 = l;
    
    // linkedList l2 = l;

    l.prettyPrint();
    l2.prettyPrint();

    return 0;
}