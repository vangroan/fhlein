
#ifndef DARRAY_H
#define DARRAY_H

#define INITIAL_DARRAY_CAPACITY 64
#define DARRAY_BOUNDS_CHECK 1

#include <stdlib.h>

/* TODO: Currently only works when the type name is basic. eg. int, float or
 * typedeffed. It fails when a type contains an asterisk, struct or enum.
 */

/*
 * The common header struct that will be inlined into every dynamic array.
 */
struct DArrayHeader {
	size_t capacity;
	size_t size; /* Number of elements */
	size_t elemSize;
};

void darrayHeader_init(struct DArrayHeader *self, size_t elemSize) {
	self->capacity = INITIAL_DARRAY_CAPACITY;
	self->size = 0;
	self->elemSize = elemSize;
}

/*
 * Macros for declaring a dynamic array of a concrete type. They must be
 * declared once per type.
 */

#define DArrayName(T) DArray_##T

/* Use this macro for non-pointer or typedef. */
#define DeclareDArray(T) \
	struct DArrayName(T) { struct DArrayHeader header; T *data; };

#define DArray_Init(T) \
	void _darray_init_##T(struct DArrayName(T) *self, size_t elemSize) { \
		darrayHeader_init((struct DArrayHeader *)self, elemSize); \
		self->data = malloc(self->header.size * self->header.elemSize); \
	}

#define DArray_Free(T) \
	void _darray_free_##T(struct DArrayName(T) *self) { \
		free(self->data); \
	}

#define DArray(T) \
	struct DArrayName(T)

/*
 * Macros for public access. These can be called like functions.
 */

#define darray_init(T, da) \
	(_darray_init_##T(da, sizeof(T)))

#define darray_free(T, da) \
	(_darray_free_##T(da))

#define darray_append(T, da, el) \
	(_darray_append(da, el))

#endif
