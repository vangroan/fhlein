
#ifndef FHLEIN_ENTITY_H
#define FHLEIN_ENTITY_H

typedef unsigned int EntityId;

struct Entity {
	EntityId id;
	struct Entity *next;
	/* TODO: Tags for lookup */
};

#endif
