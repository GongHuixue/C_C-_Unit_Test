#include <stdio.h>

typedef struct test_a TEST_A;

struct test_b {
	int x;
	int y;
};

int main() {
	struct test_b b;
	b.x = 0;
	b.y = 1;

	TEST_A a;

	printf(" %d, %d\n", b.x, b.y);
	return 0;
}
