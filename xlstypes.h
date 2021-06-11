#ifndef XLS_TYPES_INC
#define XLS_TYPES_INC

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif
#include <sys/types.h>

typedef unsigned char BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

#ifdef _WIN32
typedef unsigned __int64 unsigned64_t;
#else
typedef uint64_t unsigned64_t;
#endif

#endif
