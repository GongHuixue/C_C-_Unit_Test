#include <iostream>
#include <assert.h>

using namespace std;

class A{
	private:
		int a1;
	protected:
		int a2;
	public:
		int a3;

	A() {
		a1 = 1;
		a2 = 2;
		a3 = 3;
	}

	void fun() {
		cout << a1 << endl;
		cout << a2 << endl;
		cout << a3 << endl;
	}
};

class B: protected A {
	public:
		int a;
		B(int i){
			a = i;
		}
	
	void funb() {
		cout << a1 << endl;
		cout << a2 << endl;
		cout << a3 << endl;
	}
};

int main() {
	B b(10);
	
	cout << b.a << endl;
	
	b.funb();
	b.fun();
		
	return 0;
}
