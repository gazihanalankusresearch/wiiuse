
#include <stdio.h>
#include <stdlib.h>
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

// if you are going to find them one by one, use a separate bunch for each find.
// init a big one in the beginning (user supplies number) and then let the user find them one by one, and I use pointers within the original array. 

wiimote** wiimotes;
int wiimote_capacity = 0;
int numwiimotes = 0;

	

void wus_init(int num_remotes_desired)
{
	wiimotes = wiiuse_init(num_remotes_desired);
	wiimote_capacity = num_remotes_desired;
}
int wus_find_and_connect(int num_remotes_desired)
{
	wiiuse_find(wiimotes, wiimote_capacity, num_remotes_desired);
	int num_connected = wiiuse_connect(wiimotes, num_remotes_desired);

	int oldNum = numwiimotes;
	numwiimotes += num_connected;

	int leds[4];
	leds[0] = WIIMOTE_LED_1;
	leds[1] = WIIMOTE_LED_2;
	leds[2] = WIIMOTE_LED_3;
	leds[3] = WIIMOTE_LED_4;

	for (int i = oldNum; i < numwiimotes; ++i)
	{
		wiiuse_set_leds(wiimotes[i], leds[i]);
		wiiuse_rumble(wiimotes[i], 1);
	}

#ifndef WIIUSE_WIN32
	usleep(200000);
#else
	Sleep(200);
#endif

	for (int i = oldNum; i < numwiimotes; ++i)
	{
		wiiuse_rumble(wiimotes[i], 0);
		wus_poll();
	}

	return num_connected;
}

int wus_is_connected(int wmi)
{
	return wmi < numwiimotes && wiimotes[wmi] != NULL && WIIMOTE_IS_CONNECTED(wiimotes[wmi]);
}

int wus_any_connected()
{
	for (int i = 0; i < numwiimotes; ++i)
	{
		if (wus_is_connected(i))
		{
			return 1;
		}
	}
	return 0;
}

int wus_poll()
{
	return wiiuse_poll(wiimotes, wiimote_capacity);
} // call the functions below only when the poll returned nonzero

int16_t wus_get_buttons_pressed(int wmi)
{
	return wiimotes[wmi]->btns & ~wiimotes[wmi]->btns_held;
}

int16_t wus_get_buttons_held(int wmi)
{
	return wiimotes[wmi]->btns_held;
}

int16_t wus_get_buttons_released(int wmi)
{
	return wiimotes[wmi]->btns_released;
}

void wus_start_accel(int wmi)
{
	wiiuse_motion_sensing(wiimotes[wmi], 1);
}

void wus_stop_accel(int wmi)
{
	wiiuse_motion_sensing(wiimotes[wmi], 1);
}

void wus_start_gyro(int wmi)
{
	if (WIIUSE_USING_EXP(wiimotes[wmi])) {
		wiiuse_set_motion_plus(wiimotes[wmi], 2);    // nunchuck pass-through
		printf("nunchuk");
	}
	else 
	{
		wiiuse_set_motion_plus(wiimotes[wmi], 1);    // standalone
		printf("standalone");
	}
}

void wus_stop_gyro(int wmi)
{
	wiiuse_set_motion_plus(wiimotes[wmi], 0);
}

int wus_accel_received(int wmi)
{
	return wiimotes[wmi]->accel_received;
}

void wus_get_accel(int wmi, float *accel)
{
	accel[0] = wiimotes[wmi]->gforce.x;
	accel[1] = wiimotes[wmi]->gforce.y;
	accel[2] = wiimotes[wmi]->gforce.z;
}

int wus_gyro_received(int wmi)
{
	return wiimotes[wmi]->exp.mp.raw_gyro_received;
}

void wus_get_gyro(int wmi, float *gyro)
{
	gyro[0] = wiimotes[wmi]->exp.mp.angle_rate_gyro.pitch;
	gyro[1] = wiimotes[wmi]->exp.mp.angle_rate_gyro.yaw;
	gyro[2] = wiimotes[wmi]->exp.mp.angle_rate_gyro.roll;
}

void wus_cleanup()
{
	wiiuse_cleanup(wiimotes, numwiimotes);
}


