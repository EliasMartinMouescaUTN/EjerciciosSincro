#include <time.h>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define sleep(ms) Sleep(ms)
#else
    #include <unistd.h>
    #include <sys/time.h>
    #define sleep(ms) usleep((ms) * 1000)
#endif

#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_GRAY    "\x1b[90m"


#define COLOR_PRODUCTOR    COLOR_GREEN
#define COLOR_CONSUMIDOR   COLOR_BLUE

