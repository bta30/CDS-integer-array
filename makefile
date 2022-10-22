CC=gcc
CFLAGS=-O2

all: concurrent sequential

concurrent: concurrent.c shared.o
	$(CC) $(CFLAGS) -pthread -o concurrent concurrent.c shared.o

sequential: sequential.c shared.o
	$(CC) $(CFLAGS) -o sequential sequential.c shared.o

shared.o: shared.c
	$(CC) $(CFLAGS) -c shared.c

clean:
	rm *.o sequential concurrent
