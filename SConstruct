
import os

env = Environment(
	tools=['mingw'],
	CFLAGS='--std=c99 -Wall -Wextra -Wpedantic',
	CPPPATH=['src'],
	ENV={ 'PATH' : os.environ.get('PATH') }
)

files = Glob('src/*.c')
source = ['test/main.c'] + files

env.Program('build/test', source=source)
