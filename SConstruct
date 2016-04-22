
# Download SDL 2.0.4 mingw
# Copy the following
# {SDL2 folder}/i686-w64-mingw32/bin/* -> build/
# {SDL2 folder}/i686-w64-mingw32/include/*.h -> include/SDL2/
# {SDL2 folder}/i686-w64-mingw32/lib/*.a -> lib/

import os

env = Environment(
	tools=['mingw'],
	CFLAGS='-g -m32 --std=c99 -Wall -Wextra -Wpedantic',
	CPPPATH=['src', 'include'],
	LIBS=['mingw32', 'SDL2main', 'SDL2'],
	LIBPATH='lib',
	ENV={ 'PATH' : os.environ.get('PATH') }
)

files = Glob('src/*.c') + Glob('src/collections/*.c') + Glob('src/components/*.c') + Glob('src/systems/*.c')
source = ['test/main.c'] + files

env.Program('build/test', source=source)
