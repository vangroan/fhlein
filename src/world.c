
#include "world.h"

void
world_init(struct World *self) {
	self->components = componentStore_new();
	self->entities = entitypool_new();
	self->tilemap = tilemap_new(1024, 1024);
}

void
world_free(struct World *self) {
	componentStore_free(self->components);
	entitypool_free(self->entities);
	tilemap_free(self->tilemap);
}

struct Entity *
world_create_entity(struct World *self) {
	return create_entity(self->entities);
}

bool
world_destroy_entity(struct World *self, struct Entity *entity) {
	return destroy_entity(self->entities, entity);
}

bool world_set_component(struct World *self, enum ComponentKind compKind,
	struct Entity *entity, void *component) {

	switch (compKind) {
	#define C(type, name) \
		case ck##type: \
			((struct type *)component)->entityId = entity->id; \
			componentStore_add(type, self->components, name, (struct type *)component); \
		return true;
	COMPONENT_LIST
	#undef C
	default: return false;
	}
}
