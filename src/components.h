
#ifndef FHLEIN_COMPONENTS_H
#define FHLEIN_COMPONENTS_H

#include <stdlib.h>
#include "entity.h"

#include "components/position.h"

#define COMPONENT_LIST \
	C(Position, position)

enum ComponentKind {
	ckNone,
	#define C(type, name) ck##type,
		COMPONENT_LIST
	#undef C
	NumComponentTypes
};

/* TODO: Currently components will be stored in linked lists. It's an ugly thing
 * at the moment as the entity's id and linked list pointer needs to be in the
 * component struct.
 *
 * In the future, they be stored in arrays and indexed.
 */
struct ComponentStore {
	#define C(type, name) struct type *name;
		COMPONENT_LIST
	#undef C
};

struct ComponentStore *componentStore_new();
void componentStore_free(struct ComponentStore *self);

/*
 * Accessor functions
 */

#define C(type, name) \
	void _componentStore_add_##name(struct ComponentStore *self, struct type *component );
COMPONENT_LIST
#undef C

/* type: Component type
 * cs: Pointer to component store instance
 * member: Component array member name in component store
 * comp: Pointer to component instance */
#define componentStore_add(type, cs, member, comp) \
	_componentStore_add_##member(cs, (struct type *)comp)


#endif
