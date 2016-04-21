
#ifndef TEST_DARRAY_H
#define TEST_DARRAY_H

#include "collections/darray.h"

/*
 * Concrete implementation for int
 */

DeclareDArray(int)
DArray_Init(int)
DArray_Free(int)

void test_darray_init() {
	DArray(int) da;
	darray_init(int, &da);
	darray_free(int, &da);
}

#endif
