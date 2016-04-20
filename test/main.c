
#include <stdbool.h>
#include <stdio.h>
#include "entitypool.h"

void
assert(bool condition, const char *message) {
	if (!condition) {
		printf("Assertion failed: %s\n", message);
		exit(1);
	}
}

void
test_entitypool() {
	struct EntityPool *ep = fl_entitypool_new();
	struct Entity *e = fl_create_entity(ep);

	fl_destroy_entity(ep, e);
	assert(ep->entities == NULL, "Should free entity");
	fl_entitypool_free(ep);
}

int
main (int argc, char *argv[]) {
	printf("Starting tests\n");
	test_entitypool();
	printf("Tests done\n");
	return 0;
}
