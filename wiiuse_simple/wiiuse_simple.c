
#include <stdio.h>
#include "wiiuse_simple.h"

int test_wiiuse_simple()
{
	struct wiimote_t** wm = wiiuse_init(1);

	if (wm == NULL)
	{
		printf("wm is null\n");
	}

	printf("hello from test_wiiuse_simple\n");
	return 0;
}
