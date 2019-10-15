CC = gcc
CFLAGS = -Wall
EXEC = bfi
HEADERS = bfi.h utils.h
OBJECTS = main.o bfi.o
.PHONY = default build clean

default: build

build: $(EXEC)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

run: build
	./$(EXEC) ${ARGS}

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC)
