#include "./xlsstruct.h"

int xls_is_bigendian(void);
DWORD xlsIntVal(DWORD i);
unsigned short xlsShortVal(short s);

void xlsConvertHeader(OLE2Header *h);
void xlsConvertPss(PSS *pss);

void xlsConvertDouble(BYTE *d);
void xlsConvertBof(BOF *b);
void xlsConvertBiff(BIFF *b);
void xlsConvertWindow(WIND1 *w);
void xlsConvertSst(SST *s);
void xlsConvertXf5(XF5 *x);
void xlsConvertXf8(XF8 *x);
void xlsConvertFont(FONT *f);
void xlsConvertFormat(FORMAT *f);
void xlsConvertBoundsheet(BOUNDSHEET *b);
void xlsConvertColinfo(COLINFO *c);
void xlsConvertRow(ROW *r);
void xlsConvertMergedcells(MERGEDCELLS *m);
void xlsConvertCol(COL *c);
void xlsConvertFormula(FORMULA *f);
void xlsConvertFormulaArray(FARRAY *f);
void xlsConvertHeader(OLE2Header *h);
void xlsConvertPss(PSS *pss);

#define W_ENDIAN(a) a = xlsShortVal(a)
#define D_ENDIAN(a) a = xlsIntVal(a)
