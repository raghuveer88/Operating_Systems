CC      = gcc
RM      = rm -f


default: all

all: 518

518: 518.c
	$(CC) 518.c -o 518 -Wall -pthread
clean veryclean:
	$(RM) 518

