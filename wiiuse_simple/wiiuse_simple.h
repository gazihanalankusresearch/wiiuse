
#include <wiiuse.h>

#ifdef WIIUSE_SIMPLE_COMPILE_LIB
#define WIIUSE_SIMPLE_EXPORT WIIUSE_EXPORT_DECL
#else
#define WIIUSE_SIMPLE_EXPORT WIIUSE_IMPORT_DECL
#endif

WIIUSE_SIMPLE_EXPORT extern int test_wiiuse_simple();

WIIUSE_SIMPLE_EXPORT extern void wus_init(int num_remotes_desired);
WIIUSE_SIMPLE_EXPORT extern int wus_find_and_connect(int num_remotes_desired);
WIIUSE_SIMPLE_EXPORT extern int wus_is_connected(int wmi);
WIIUSE_SIMPLE_EXPORT extern int wus_any_connected();
WIIUSE_SIMPLE_EXPORT extern int wus_poll();
WIIUSE_SIMPLE_EXPORT extern int16_t wus_get_buttons_pressed(int wmi);
WIIUSE_SIMPLE_EXPORT extern int16_t wus_get_buttons_held(int wmi);
WIIUSE_SIMPLE_EXPORT extern int16_t wus_get_buttons_released(int wmi);
WIIUSE_SIMPLE_EXPORT extern void wus_start_accel(int wmi);
WIIUSE_SIMPLE_EXPORT extern void wus_stop_accel(int wmi);
WIIUSE_SIMPLE_EXPORT extern void wus_start_gyro(int wmi);
WIIUSE_SIMPLE_EXPORT extern void wus_stop_gyro(int wmi);
WIIUSE_SIMPLE_EXPORT extern int wus_accel_received(int wmi);
WIIUSE_SIMPLE_EXPORT extern void wus_get_accel(int wmi, float *x, float *y, float *z);
WIIUSE_SIMPLE_EXPORT extern int wus_gyro_received(int wmi);
WIIUSE_SIMPLE_EXPORT extern void wus_get_gyro(int wmi, float *x, float *y, float *z);
WIIUSE_SIMPLE_EXPORT extern void wus_cleanup();
