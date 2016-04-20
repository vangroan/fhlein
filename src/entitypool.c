
#include "entitypool.h"

/* ------
 * Public
 * ------ */

struct EntityPool *
fl_entitypool_new() {
	struct EntityPool *self = malloc(sizeof(struct EntityPool));
	self->nextId = 0;
	self->entities = NULL;
	self->count = 0;
	return self;
}

void
fl_entitypool_free(struct EntityPool *self) {
	free(self);
}

struct Entity *
fl_create_entity(struct EntityPool *self) {
	struct Entity *e = malloc(sizeof(struct Entity));
	e->id = self->nextId++;
	e->next = self->entities;
	self->entities = e;
	self->count++;
	return e;
}

int
fl_destroy_entity(struct EntityPool *self, struct Entity *entity) {
	struct Entity **cursor = &self->entities;
	while (*cursor) {
		if (*cursor == entity) {
			/* TODO: Recycle id */
			struct Entity *found = *cursor;
			*cursor = found->next;
			free(found);
			self->count--;
			return true;
		} else {
			cursor = &(*cursor)->next;
		}
	}
	return false;
}
