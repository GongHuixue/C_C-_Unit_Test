#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef list<int> LISTINT;
typedef list<char> LISTCHAR;

int main() {
	LISTINT listone;
	LISTINT::iterator i;
	LISTINT::iterator ir;

	//add data from head
	listone.push_front(2);
	listone.push_front(1);

	//add data from end
	listone.push_back(3);
	listone.push_back(4);

	cout << "begin-----end: " << endl;

	for(i = listone.begin(); i != listone.end(); i++)
		cout << *i << " " << endl;

	for(ir = listone.end(); ir != listone.begin(); --ir)
		cout << *ir << " " << endl;
	return 0;
}
