#ifndef __ERROR_H__
#define __ERROR_H__

#include "error_table.h"
#define E(c, m) c,
typedef enum
{
	ERROR_TABLE
			NUM_ERRORS
} ECODE;
#undef E

void show_error(ECODE error_code);

#endif // __ERROR_H__

