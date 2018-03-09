#include <iostream>

using namespace std;

void fun() {
	static int n = 10;
	int m = 10;
	n++;
	m++;
	cout << "n:" << n << endl;
	cout << "m:" << m << endl;
}

int main() {
	fun();
	fun();
	fun();
	return 0;
}
