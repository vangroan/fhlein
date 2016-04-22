
#include "components.h"

struct ComponentStore *
componentStore_new() {
	struct ComponentStore *self = malloc(sizeof(struct ComponentStore));

	#define C(type, name) self->name = NULL;
		COMPONENT_LIST
	#undef C

	return self;
}

void
componentStore_free(struct ComponentStore *self) {
	#define C(type, name) free(self->name);
		COMPONENT_LIST
	#undef C
	free(self);
}

#define C(type, name) \
void _componentStore_add_##name(struct ComponentStore *self, struct type *component ) { \
	component->next = self->name; \
}
COMPONENT_LIST
#undef C
