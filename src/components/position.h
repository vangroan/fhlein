
#ifndef FHLEIN_COMPONENT_POSITION_H
#define FHLEIN_COMPONENT_POSITION_H

#include "entity.h"

/* Describes an entity's coordinates on the map. The coordinates are described
 * with i, j and k, ie. Right, down, towards.*/
struct Position {
	/* TODO: Move entity-component mapping to somewhere else */
	EntityId entityId;
	int i;
	int j;
	int k;
	/* TODO: Store in array and not linked list */
	struct Position *next;
};

#endif
