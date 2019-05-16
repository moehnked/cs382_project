CC=gcc
CFLAGS=-g -Wshadow -pthread -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wno-return-local-addr -Wuninitialized
#DEPS = 
#OBJ =

all: sequ

sequ: sequ.o
	$(CC) $(CFLAGS) -o sequ main.c

sequ.o: main.c
	$(CC) -c main.c

clean:
	rm -rf sequ *.o *~ \#*