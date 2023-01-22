CC = gcc
DEPS = *.h
all: langton.o visualiser.o main.c
	$(CC) -o langton main.c langton.o visualiser.o -lncursesw
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@
run:
	./langton
clean:
	rm -f langton *.o