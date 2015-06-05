

#include <stdio.h>
#include "wiiuse_simple.h"


int main(int argc, char** argv) {
	printf("wiiuse_simple_example ran\n");
	test_wiiuse_simple();
	printf("test returned\n");

	int tmp;
	scanf("%d", &tmp);
	return 0;
}