
#ifndef FHLEIN_ENTITYPOOL_H
#define FHLEIN_ENTITYPOOL_H

#include <stdbool.h>
#include <stdlib.h>
#include "entity.h"

/* TODO: Store entities in array */

struct EntityPool {
	EntityId nextId;
	struct Entity *entities;
	unsigned int count;
};

struct EntityPool *fl_entitypool_new();
void fl_entitypool_free(struct EntityPool *self);
struct Entity *fl_create_entity(struct EntityPool *self);
int fl_destroy_entity(struct EntityPool *self, struct Entity *entity);

#endif
