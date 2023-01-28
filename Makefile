export LD_LIBRARY_PATH=$(PWD):LD_LIBRARY_PATH
all:
	gcc -L $(PWD) -Wall -o ant main.c -lant
	./ant LLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRR
library:
	gcc -fPIC -c langton.c -o langton.o
	gcc -fPIC -c visualiser.c -o visualiser.o 
	gcc -shared langton.o \
    visualiser.o -o libant.so -lncursesw
clean:
	rm -f ant *.o *.so 