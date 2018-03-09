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

class B: public A {
	public:
		int a;
		int b;
		B(){
		a = a2;
		//b = a1;
		cout << a << endl;
		cout << b << endl;
	}
};

int main() {
	A m_a;
	B m_b;	

	//m_a.a1 = 10;
	//m_a.a2 = 10;
	m_a.a3 = 10;

	m_a.fun();
	
	return 0;
}
