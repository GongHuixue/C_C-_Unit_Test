#include <stdio.h>

typedef int (*FuncArr)(int a);

static int fun1(int index);
static int fun2(int index);
static int fun3(int index);
static int fun4(int index);

static FuncArr FunArr[] = {
				fun1, fun2, fun3, fun4
			   };


int fun1(int index)
{
	printf("fun1 %d\n", index);
	return 0;
}

int fun2(int index)
{
	printf("fun2 %d\n", index);
	return 0;
}

int fun3(int index)
{
	printf("fun3 %d \n", index);
	return 0;
}

int fun4(int index)
{
	printf("fun4 %d\n", index);
	return 0;
}



int main(void)
{
	int i = 0;
	
	for(i = 0; i < 4; i++)
		FunArr[i](i);

	getchar();

}
