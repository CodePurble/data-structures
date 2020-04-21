#ifndef hashTable_h
#define hashTable_h
#include <string>

class hashTable
{
	private:
		std::string table[10];
		int hashFunction(std::string s);
	
	public:
		/* hashTable(); */
		/* ~hashTable(); */
		void prettyPrint();
		void addElement(std::string str);
		bool lookup(std::string str);
};

#endif
