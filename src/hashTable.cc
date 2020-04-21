#include "hashTable.h"
#include <iostream>

int hashTable::hashFunction(std::string s)
{
	int index = 0;
	for(int i = 0; i < s.length(); i++){
		index += (int) s[i];
	}

	return(index % 10);
}

void hashTable::addElement(std::string str)
{
	int index = hashFunction(str);

	while(table[index] != "")
		index++;

	table[index] = str;
}

bool hashTable::lookup(std::string str)
{
	int index = hashFunction(str);
	if(table[index] != "")
		return true;
	else
		return false;
}

void hashTable::prettyPrint()
{
	for(int i = 0; i < 10; i++)
		std::cout << i << table[i] << std::endl;
}
