

#include <stdio.h>
#include "wiiuse_simple.h"


int main(int argc, char** argv) {
	wus_init(1);
	int num_connected = wus_find_and_connect(1);

	if (num_connected == 0)
	{
		printf("could not connect.");
		return 1;
	}

	float accel[3];
	float gyro[3];

	int wmi = 0;

	wus_start_accel(wmi);
	wus_start_gyro(wmi);

	while (1)
	{
		if(wus_poll())
		{
			int16_t btns_pressed = wus_get_buttons_pressed(wmi);
			int16_t btns_held = wus_get_buttons_held(wmi);
			int16_t btns_released = wus_get_buttons_released(wmi);
			printf("."); 
			fflush(0);
			if (wus_accel_received(wmi))
			{
				wus_get_accel(wmi, accel + 0, accel + 1, accel + 2);
				printf("\naccel: %f %f %f", accel[0], accel[1], accel[2]);
			}
			if (wus_gyro_received(wmi))
			{
				wus_get_gyro(wmi, gyro + 0, gyro + 1, gyro + 2);
				printf("\ngyro: %f %f %f", gyro[0], gyro[1], gyro[2]);
			}
		}
	}

	wus_cleanup();

	printf("wiiuse_simple_example ran\n");
	test_wiiuse_simple();
	printf("test returned\n");

	int tmp;
	scanf("%d", &tmp);
	return 0;
}