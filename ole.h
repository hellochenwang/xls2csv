#ifndef OLE_INCLUDE
#define OLE_INCLUDE

#ifdef __cplusplus
#include <cstdio>  // FILE *
#else
#include <stdio.h>  // FILE *
#endif

#include "./xlstypes.h"

#if defined(_AIX) || defined(__sun)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

typedef struct TIME_T {
  DWORD LowDate;
  DWORD HighDate;
} TIME_T;

typedef struct OLE2Header {
  DWORD id[2];  // D0CF11E0 A1B11AE1
  DWORD clid[4];
  WORD verminor;  // 0x3e
  WORD verdll;    // 0x03
  WORD byteorder;
  WORD lsectorB;
  WORD lssectorB;

  WORD reserved1;
  DWORD reserved2;
  DWORD reserved3;

  DWORD cfat;  // count full sectors
  DWORD dirstart;

  DWORD reserved4;

  DWORD sectorcutoff;  // min size of a standard stream ; if less than this then
                       // it uses short-streams
  DWORD sfatstart;     // first short-sector or EOC
  DWORD csfat;         // count short sectors
  DWORD difstart;      // first sector master sector table or EOC
  DWORD cdif;          // total count
  DWORD MSAT[109];     // First 109 MSAT
} OLE2Header;

#pragma pack(pop)

//-----------------------------------------------------------------------------------
typedef struct st_olefiles {
  long count;
  struct st_olefiles_data {
    char* name;
    DWORD start;
    DWORD size;
  } * file;
} st_olefiles;

typedef struct OLE2 {
  FILE* file;
  const void* buffer;
  size_t buffer_len;
  size_t buffer_pos;

  WORD lsector;
  WORD lssector;
  DWORD cfat;
  DWORD dirstart;

  DWORD sectorcutoff;
  DWORD sfatstart;
  DWORD csfat;
  DWORD difstart;
  DWORD cdif;

  DWORD* SecID;  // regular sector data
  DWORD SecIDCount;

  DWORD* SSecID;  // short sector data
  DWORD SSecIDCount;

  BYTE* SSAT;  // directory of short sectors
  DWORD SSATCount;

  st_olefiles files;
} OLE2;

typedef struct OLE2Stream {
  OLE2* ole;
  DWORD start;
  size_t pos;
  size_t cfat;
  size_t size;
  size_t fatpos;
  BYTE* buf;
  DWORD bufsize;
  BYTE eof;
  BYTE sfat;  // short
} OLE2Stream;

#if defined(_AIX) || defined(__sun)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

typedef struct PSS {
  char name[64];
  WORD bsize;
  BYTE type;  // STGTY
#define PS_EMPTY 00
#define PS_USER_STORAGE 01
#define PS_USER_STREAM 02
#define PS_USER_ROOT 05
  BYTE flag;  // COLOR
#define BLACK 1
  DWORD left;
  DWORD right;
  DWORD child;
  WORD guid[8];
  DWORD userflags;
  TIME_T time[2];
  DWORD sstart;
  DWORD size;
  DWORD proptype;
} PSS;

#pragma pack(pop)

ssize_t ole2_read(void* buf, size_t size, size_t count, OLE2Stream* olest);
OLE2Stream* ole2_sopen(OLE2* ole, DWORD start, size_t size);
int ole2_seek(OLE2Stream* olest, DWORD ofs);
OLE2Stream* ole2_fopen(OLE2* ole, const char* file);
void ole2_fclose(OLE2Stream* ole2st);
OLE2* ole2_open_file(const char* file);
OLE2* ole2_open_buffer(const void* buffer, size_t len);
void ole2_close(OLE2* ole2);

#endif
