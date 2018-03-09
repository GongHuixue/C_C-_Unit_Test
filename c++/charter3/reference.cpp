#include <iostream>

using namespace std;

/*
**a):The Reference in C++ is just like a const pointer.
**b):The Reference must be initialized.
**c):The Reference will occupy memory.
*/

int main() {
	int i = 10;

	int &j = i;	// int &j = i  <-----> int *const j = &i;
	int *const k = &i;
	int const *l = &i;

	cout << i << " " << j << endl;
	cout << &i << " " << &j << endl;

	j++;	// increase j will increase both i and j;

	cout << i << " " << j << endl;
	cout << &i << " " << &j << endl;	//i and j have the same address.

	cout << *k << " " << i << endl;
	cout << k << " " << &i << endl;	//i and j have the same address.
	
	cout << *l << " " << i << endl;
	cout << l << " " << &i << endl;	//i and j have the same address.
	return 0;
}
