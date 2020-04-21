#include "hashTable.h"
#include <iostream>
using namespace std;

int main()
{
	hashTable t;

	t.addElement("Ram");
	t.prettyPrint();

	cout << t.lookup("Ram") << endl << t.lookup("asasd") << endl;

	return 0;
}
