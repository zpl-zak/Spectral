//#pragma GCC warning "warning message"         // gcc/clang only pragma
//#pragma message ( "your warning text here" )  // msc pragma which works in gcc too, albeit not as intended

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned int   dword;
typedef unsigned int   rgba;

#define countof(x) ((int)(sizeof(x) / sizeof(0[x])))

#define joint(a,b) a##b
#define join(a,b)  joint(a,b)

#define do_once  static int join(once,__LINE__) = 1; for( ; join(once,__LINE__) ; join(once,__LINE__) = 0 )
#define FIXME(msg) printf("FIXME: " msg " (%s:%d)\n", __FILE__, __LINE__)

#ifdef _MSC_VER
#define bswap16  _byteswap_ushort
#define bswap32  _byteswap_ulong
#define bswap64  _byteswap_uint64
#define __thread __declspec(thread)
#else
#define bswap16 __builtin_bswap16
#define bswap32 __builtin_bswap32
#define bswap64 __builtin_bswap64
#endif

#ifdef _WIN32
#define mkdir(p,m)    mkdir(p)
#else
#include <limits.h>
#define MAX_PATH PATH_MAX // (defined in limits.h)

#define RGB(r,g,b) ((dword)(((byte)(r)|((word)((byte)(g))<<8))|(((dword)(byte)(b))<<16)))

#define GetFocus() 0
#define GetAsyncKeyState(vk) 0
#define VK_SNAPSHOT 0
#define strcmpi       strcasecmp
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define FALSE 0
#define ShowCursor(...)     (void)0
#define ClipCursor(...)     (void)0
#define GetWindowRect(...)  (void)0
typedef int RECT;
#define _popen popen
#define _pclose pclose
#ifdef __GNUC__ // also, clang
    int __argc;
    char **__argv;
    __attribute__((constructor)) void init_argcv(int argc, char **argv) {
        __argc = argc;
        __argv = argv;
    }
#endif
#endif

// leading and trailing zeros count. UB if x == 0
#if defined _MSC_VER && !defined __clang__
#include <immintrin.h>
#define __builtin_clz(x)   _lzcnt_u32(x)
#define __builtin_clzll(x) _lzcnt_u64(x)
#define __builtin_ctz(x)   _tzcnt_u32(x)
#define __builtin_ctzll(x) _tzcnt_u64(x)
#endif

// safe leading and trailing zeros count. no UB
#define __builtin_safe_clz(x)   ((x) ? __builtin_clz(x)   : 32)
#define __builtin_safe_clzll(x) ((x) ? __builtin_clzll(x) : 64)
#define __builtin_safe_ctz(x)   ((x) ? __builtin_ctz(x)   : 32)
#define __builtin_safe_ctzll(x) ((x) ? __builtin_ctzll(x) : 64)


#define ifdef(sym,t,...)  ifdef_##sym(t,__VA_ARGS__)
#define ifndef(sym,t,...) ifndef_##sym(t,__VA_ARGS__)

#ifdef _WIN32
#define ifdef_win32(t,...)  t
#define ifndef_win32(t,...) __VA_ARGS__
#else
#define ifndef_win32(t,...)  t
#define ifdef_win32(t,...) __VA_ARGS__
#endif

#ifdef __linux__
#define ifdef_linux(t,...)  t
#define ifndef_linux(t,...) __VA_ARGS__
#else
#define ifndef_linux(t,...)  t
#define ifdef_linux(t,...) __VA_ARGS__
#endif

#ifdef __APPLE__
#define ifdef_osx(t,...)  t
#define ifndef_osx(t,...) __VA_ARGS__
#else
#define ifndef_osx(t,...)  t
#define ifdef_osx(t,...) __VA_ARGS__
#endif
