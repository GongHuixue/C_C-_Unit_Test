#include <iostream>

using namespace std;

static int n;

void fun() {
	n++;
	cout << n << endl;
}

int main() {
	cout << n << endl;
	n = 20;
	fun();
	return 0;
}
