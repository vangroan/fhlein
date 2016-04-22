
#ifndef FHLEIN_TEST_ENTITYPOOL_H
#define FHLEIN_TEST_ENTITYPOOL_H

#include "entitypool.h"
#include "repr.h"

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

#endif
