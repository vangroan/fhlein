
#include "tilemap.h"

struct Tilemap *
tilemap_new(int width, int height) {
	struct Tilemap *self = malloc(sizeof(struct Tilemap));
	self->width = width;
	self->height = height;
	self->data = malloc(self->width * self->height * sizeof(TileId));
	return self;
}

void
tilemap_free(struct Tilemap *self) {
	free(self->data);
	free(self);
}

TileId
tilemap_get(struct Tilemap *self, int i, int j) {
	return self->data[i + j * self->width];
}

void
tilemap_set(struct Tilemap *self, int i, int j, TileId tile) {
	self->data[i + j * self->width] = tile;
}
