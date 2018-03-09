#include <iostream>

using namespace std;

struct Bit_Test1{
	int a;
	int b;
	char c;
}Test1;

struct Bit_Test2{
	int a:2;
	int b:2;
	int c:1;
	int d:3;
}Test2;

class Bit_Filed {
	public:
	unsigned int a;
	char b;
}bit;

int main() {
	cout << "a size " << sizeof(bit.a) << endl;
	
	cout << "b size " << sizeof(bit.b) << endl;

	cout << "Test1 Size " << sizeof(Test1) << endl;
	cout << "Test2 Size " << sizeof(Test2) << endl;
	return 0;
}
