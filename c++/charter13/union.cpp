#include <iostream>

using namespace std;

class MyClass{
	private:	
		int a;
	public:
		MyClass():a(0) {}	
};

union test{
	char a;
	int c;
#if 0
	static int b;
	
	MyClass m_test;
	MyClass &m_p = m_test;
#endif
};

int main() {
	union test m;
	
	m.a = 'a';
	

	int i = m.a;	

	cout << "a=" << m.a <<  " " << "c=" << m.c << endl;

	cout << "size " << sizeof(test) << endl;
	return 0;
}
