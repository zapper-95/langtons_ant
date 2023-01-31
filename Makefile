export LD_LIBRARY_PATH=$(PWD):LD_LIBRARY_PATH 
all:
	gcc -L $(PWD) -Wall -o ant main.c -lant
	./ant LLRR
library:
	gcc -fPIC -c langton.c -o langton.o -Wall
	gcc -fPIC -c visualiser.c -o visualiser.o -Wall
	gcc -shared langton.o \
    visualiser.o -o libant.so -lncursesw -Wall
clean:
	rm -f ant *.o *.so 