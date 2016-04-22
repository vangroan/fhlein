
#ifndef FHLEIN_TILEMAP_H
#define FHLEIN_TILEMAP_H

#include <stdlib.h>

typedef int TileId;

struct Tilemap {
	TileId *data;
	int width;
	int height;
};

struct Tilemap *tilemap_new(int width, int height);
void tilemap_free(struct Tilemap *self);
TileId tilemap_get(struct Tilemap *self, int i, int j);
void tilemap_set(struct Tilemap *self, int i, int j, TileId tile);

#endif
