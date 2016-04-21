/*
 * Helper functions to print structs to stdout. Kept in their own file so that
 * other files don't depend on stdio.h
 */

#ifndef FHLEIN_REPR_H
#define FHLEIN_REPR_H

#include <stdio.h>
#include "entitypool.h"

void repr_entity(struct Entity* self);
void repr_entitypool(struct EntityPool* self);

#endif
