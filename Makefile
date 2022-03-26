CC = gcc
CFLAGS = -Werror -Wall -pedantic

all: matrix_driver

matrix_driver : main.o matrix.o int_vect.o
	$(CC) $(CFLAGS) -o matrix_driver main.o matrix.o int_vect.o
main.o : main.c matrix.h int_vect.h
	$(CC) $(CFLAGS) -c main.c

matrix.o : matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

int_vect.o : int_vect.c int_vect.h
	$(CC) $(CFLAGS) -c int_vect.c

clean :
	rm -f *.o matrix_driver