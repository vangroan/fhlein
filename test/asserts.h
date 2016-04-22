
#ifndef FHLEIN_TEST_ASSERTS_H
#define FHLEIN_TEST_ASSERTS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void
assert(bool condition, const char *message) {
	if (!condition) {
		printf("Assertion failed: %s\n", message);
		exit(1);
	}
}

#endif
