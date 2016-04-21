
#ifndef FHLEIN_ENTITY_H
#define FHLEIN_ENTITY_H

typedef unsigned int EntityId;

/*
 * Entities must be created and destroyed using the EntityPool.
 * example:
 * 		Entity *entity = create_entity(entitypool);
 * 		destroy_entity(entitypool, entity);
 */
struct Entity {
	EntityId id;
};

#endif
