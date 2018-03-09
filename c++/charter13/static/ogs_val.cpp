#include <iostream>

using namespace std;

class MyClass {
	public:
		MyClass(int a, int b, int c);
		void GetSum();
	private:
		int a, b, c;
		static int sum;
};

int MyClass::sum = 0;

MyClass::MyClass(int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;

	sum += a + b + c;
}

void MyClass::GetSum() {
	cout << "Sum = " << sum << endl;
}

int main() {
	MyClass M(1,2,3);
	M.GetSum();
	
	MyClass N(2,3,4);
	N.GetSum();
	
	return 0;
}
