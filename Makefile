CC = g++
CFLAGS = -Iinclude
LDFLAGS = -Llib -lraylib -lGL -lGLU -lX11 -lm -lpthread -ldl

objs = main.o Entity.o Cube.o

proj: $(objs)
	$(CC) -o proj $(objs) $(LDFLAGS)

main.o: main.cc Entity.h
	$(CC) -c main.cc $(CFLAGS)

Entity.o: Entity.cc Entity.h
	$(CC) -c Entity.cc ${CFLAGS}

Cube.o: Cube.cc Cube.h
	$(CC) -c Cube.cc ${CFLAGS}

run: proj
	./proj

clean:
	rm -f proj $(objs)
