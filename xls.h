#ifndef XLS_INCLUDE
#define XLS_INCLUDE

#ifdef __cplusplus
namespace xls {
extern "C" {
#endif

#include "./xlsstruct.h"
#include "./xlstool.h"
#include "./xlstypes.h"

typedef enum {
  LIBXLS_OK,
  LIBXLS_ERROR_OPEN,
  LIBXLS_ERROR_SEEK,
  LIBXLS_ERROR_READ,
  LIBXLS_ERROR_PARSE,
  LIBXLS_ERROR_MALLOC
} xls_error_t;

const char *xls_getVersion(void);
const char *xls_getError(xls_error_t code);

int xls(int debug);  // Set debug. Force library to load?
void xls_set_formula_hander(xls_formula_handler handler);

xls_error_t xls_parseWorkBook(xlsWorkBook *pWB);
xls_error_t xls_parseWorkSheet(xlsWorkSheet *pWS);

// Preferred API
// charset - convert 16bit strings within the spread sheet to this 8-bit
// encoding (UTF-8 default)
xlsWorkBook *xls_open_file(const char *file, const char *charset,
                           xls_error_t *outError);
xlsWorkBook *xls_open_buffer(const unsigned char *data, size_t data_len,
                             const char *charset, xls_error_t *outError);
void xls_close_WB(xlsWorkBook *pWB);

// Historical API
xlsWorkBook *xls_open(const char *file, const char *charset);
#define xls_close xls_close_WB

xlsWorkSheet *xls_getWorkSheet(xlsWorkBook *pWB, int num);
void xls_close_WS(xlsWorkSheet *pWS);

xlsSummaryInfo *xls_summaryInfo(xlsWorkBook *pWB);
void xls_close_summaryInfo(xlsSummaryInfo *pSI);

// utility function
xlsRow *xls_row(xlsWorkSheet *pWS, WORD cellRow);
xlsCell *xls_cell(xlsWorkSheet *pWS, WORD cellRow, WORD cellCol);

#ifdef __cplusplus
}  // extern c block
}  // namespace
#endif

#endif
