/*
 * Copyright (c) 2014.  lin_jie_long@126.com, Mon 26 Oct 2015 08:24:27 PM CST,  All rights reserved.
 */
/*
 * File Name:  virtual.cpp
 * Author:     Vanqusier(lin_jie_long@126.com)
 * EMail:      lin_jie_long@126.com
 */
#include<stdlib.h>
#include<iostream>
using namespace std;

class A {
	public:
		virtual int add(int x, int y) = 0;
		virtual int del(int x, int y) = 0;
};

class B : public A {
	public:
		int add(int x, int y) { return (x+y); }
		int del(int x, int y) { return (x-y); }
};

int main()
{
	A* a = new B();
	int add_num, del_num;
	add_num = a->add(1, 2);
	del_num = a->del(3, 4);
#if 1
	cout << "add = " << add_num << endl;
#endif	
	return 0;
}
