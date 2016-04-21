
#ifndef FHLEIN_ENTITYPOOL_H
#define FHLEIN_ENTITYPOOL_H

#include <stdbool.h>
#include <stdlib.h>
#include "entity.h"

#define INITIAL_ENTITY_SIZE 64

/*
 * Stores entities in a continuous array. May reallocate storage and invalidate
 * pointers to elements. Keep Entity ids as reference handlers instead.
 */
struct EntityPool {
	EntityId nextId;
	/* TODO: Change size, count to capacity, size */
	size_t size; /* The size of the entities array */
	struct Entity *entities;
	size_t count;
	/* TODO: Entity id to array index mapping */
	/* TODO: Tags for lookup */
};

struct EntityPool *entitypool_new();
void entitypool_free(struct EntityPool *self);
struct Entity *create_entity(struct EntityPool *self);
bool destroy_entity(struct EntityPool *self, struct Entity *entity);

/* Iterator */
struct Entity *entitypool_begin(struct EntityPool *self);
/* the end pointer of the iterator will be the last element + 1 */
struct Entity *entitypool_end(struct EntityPool *self);

#endif
