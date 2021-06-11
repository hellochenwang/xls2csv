#include "./xlsstruct.h"

void verbose(char* str);

char* codepage_decode(const char* s, size_t len, xlsWorkBook* pWB);
char* unicode_decode(const char* s, size_t len, xlsWorkBook* pWB);
char* transcode_utf16_to_utf8(const char* s, size_t len);
char* get_string(const char* s, size_t len, BYTE is2, xlsWorkBook* pWB);
DWORD xls_getColor(const WORD color, WORD def);

void xls_showBookInfo(xlsWorkBook* pWB);
void xls_showROW(struct st_row_data* row);
void xls_showColinfo(struct st_colinfo_data* col);
void xls_showCell(struct st_cell_data* cell);
void xls_showFont(struct st_font_data* font);
void xls_showXF(XF8* xf);
void xls_showFormat(struct st_format_data* format);
char* xls_getfcell(xlsWorkBook* pWB, struct st_cell_data* cell, BYTE* label);
char* xls_getCSS(xlsWorkBook* pWB);
void xls_showBOF(BOF* bof);
