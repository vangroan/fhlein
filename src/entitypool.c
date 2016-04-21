
#include "entitypool.h"


/* -------
 * Private
 * ------- */

/*
 * Checks whether the entity array should grow. Returns true if array was
 * resized, false if it wasn't.
 */
static bool
grow(struct EntityPool *self) {
	if (self->count >= self->size) {
		self->size = self->size * 2 + 10;
		realloc(self->entities, sizeof(struct Entity) * self->size);
		return true;
	}
	return false;
}

static bool
shrink(struct EntityPool *self) {
	if (self->count <= self->size / 2) {
		self->size = self->count * 2 + 10;
		realloc(self->entities, sizeof(struct Entity) * self->size);
		return true;
	}
	return false;
}

/* ------
 * Public
 * ------ */

struct EntityPool *
entitypool_new() {
	struct EntityPool *self = malloc(sizeof(struct EntityPool));
	self->nextId = 0;
	self->size = INITIAL_ENTITY_SIZE;
	self->entities = malloc(sizeof(struct Entity) * self->size);
	self->count = 0;
	return self;
}

void
entitypool_free(struct EntityPool *self) {
	free(self->entities);
	free(self);
}

struct Entity *
create_entity(struct EntityPool *self) {
	struct Entity *e = &self->entities[self->count++];
	e->id = self->nextId++;
	grow(self);
	return e;
}

bool
destroy_entity(struct EntityPool *self, struct Entity *entity) {
	size_t index = 0;
	bool found = false;
	/* Find entity in array */
	/* TODO: Use mapping for quick lookup */
	for (size_t i = 0; i < self->count; i++) {
		if (self->entities[i].id == entity->id) {
			index = i;
			found = true;
			break;
		}
	}

	if (found) {
		/* Overwrite the entity with the last one */
		self->entities[index] = self->entities[self->count-1];
		self->count--;
		shrink(self);
	}

	return found;
}

struct Entity *
entitypool_begin(struct EntityPool *self) {
	return self->entities;
}

struct Entity *
entitypool_end(struct EntityPool *self) {
	return self->entities + self->count;
}
