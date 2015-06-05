
#include <wiiuse.h>

#ifdef WIIUSE_SIMPLE_COMPILE_LIB
#define WIIUSE_SIMPLE_EXPORT WIIUSE_EXPORT_DECL
#else
#define WIIUSE_SIMPLE_EXPORT WIIUSE_IMPORT_DECL
#endif

WIIUSE_SIMPLE_EXPORT extern int test_wiiuse_simple();
