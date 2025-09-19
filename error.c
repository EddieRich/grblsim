#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "error_table.h"

#define E(c, m) m,
const char* error_message[] =
{
	ERROR_TABLE
};
#undef E

void show_error(ECODE error_code)
{
	printf("\nerror: %s\n", error_message[error_code]);
	exit(error_code);
}

