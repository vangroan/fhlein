
#ifndef FHLEIN_WORLD_H
#define FHLEIN_WORLD_H

#include <stdbool.h>

#include "components.h"
#include "entitypool.h"
#include "tilemap.h"

struct World {
	struct ComponentStore *components;
	struct EntityPool *entities;
	struct Tilemap *tilemap;
};

void world_init(struct World *self);
void world_free(struct World *self);

/* Convenience functions */
struct Entity *world_create_entity(struct World *self);
bool world_destroy_entity(struct World *self, struct Entity *entity);

/* Copies a component into the component store */
bool world_set_component(struct World *self, enum ComponentKind compKind,
	struct Entity *entity, void *component);

#endif
