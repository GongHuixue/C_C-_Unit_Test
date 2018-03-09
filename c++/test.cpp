#include <iostream>

using namespace std;

class A {
	public:
		int add(int x, int y) { return (x + y);}
		static A* create() { return new A(); }
};

static A* pa = 0;


int main()
{
	A a;
	cout << "sum = " << a.add(1,2) << endl;

	pa = A::create();
	cout << "sum = " << pa->add(2,3) << endl;
	

	return 0;
}
