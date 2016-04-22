
#include <stdbool.h>
#include <stdio.h>

#include "SDL2/SDL.h"

#include "asserts.h"
#include "test_darray.h"
#include "test_entitypool.h"
#include "world.h"

void
init_test_world(struct World *world) {
	/* Create an actor */
	struct Entity *actor = world_create_entity(world);

	/* Add a position component to the actor */
	struct Position pos;
	pos.i = 512;
	pos.j = 512;
	pos.k = 512;

	/* TODO: This is not complete. The linked list in world->components->position
	 * sets up the first pointer to this struct in the stack. The struct must be moved
	 * to the array, or the component pool must be used to allocate components, like
	 * the EntityPool. */
	world_set_component(world, ckPosition, actor, &pos);
}

void
mainloop() {
	SDL_Window *win = SDL_CreateWindow("test", 100, 100,
		320, 240, SDL_WINDOW_SHOWN);
	assert(win != NULL, SDL_GetError());

	struct World world;
	world_init(&world);
	init_test_world(&world);

	SDL_Event event;
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: running = false; break;
			}
		}
	}

	world_free(&world);

	SDL_DestroyWindow(win);
	SDL_Quit();
}

int
main (int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}

	printf("Starting tests\n");
	test_entitypool();
	test_darray_init();
	printf("Tests done\n");

	printf("Starting main loop\n");
	mainloop();

	return 0;
}
