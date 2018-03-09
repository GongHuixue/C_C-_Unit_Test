/*
 * Copyright (c) 2014.  lin_jie_long@126.com, Sun 28 Jun 2015 04:24:13 PM CST,  All rights reserved.
 */
/*
 * File Name:  template.cpp
 * Author:     Vanqusier(lin_jie_long@126.com)
 * EMail:      lin_jie_long@126.com
 */

#include <iostream>
#include <string.h>
using namespace std;
using std::cout;
using std::endl;

template <class T>
T min(T x, T y) {
	return (x < y)?x:y;
}

int main()
{
	int a1 = 1, a2 =2;
	double b1 = 1.2, b2 = 0.2;

	cout << "min int" << min(a1, a2) << endl;
	cout << "min dou" << min(b1, b2) << endl;

	return 0;
	//system("PAUSE");
}
