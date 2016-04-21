
#include <stdbool.h>
#include <stdio.h>
#include "entitypool.h"
#include "repr.h"

#include "test_darray.h"

void
assert(bool condition, const char *message) {
	if (!condition) {
		printf("Assertion failed: %s\n", message);
		exit(1);
	}
}

void
test_entitypool() {
	struct EntityPool *ep = entitypool_new();
	repr_entitypool(ep);

	struct Entity *e = create_entity(ep);
	repr_entity(e);

	create_entity(ep);
	create_entity(ep);
	repr_entity(create_entity(ep));
	repr_entitypool(ep);

	destroy_entity(ep, e);
	destroy_entity(ep, e);
	repr_entitypool(ep);
	entitypool_free(ep);
}

int
main (int argc, char *argv[]) {
	printf("Starting tests\n");
	test_entitypool();
	test_darray_init();
	printf("Tests done\n");
	return 0;
}
