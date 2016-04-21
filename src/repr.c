
#include "repr.h"

void repr_entity(struct Entity* self) {
	printf("<Entity %u>\n", self->id);
}

void repr_entitypool(struct EntityPool* self) {
	printf("<EntityPool size:%llu count:%llu>\n",
		(unsigned long long)self->size,
		(unsigned long long)self->count
	);
}
