CFLAGS=-std=c11 -Wall -g -static
SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)

9cc: $(OBJS)
		$(CC) -o 9cc $(OBJS) $(LDFLAGS)

$(OBJS): 9cc.h

test: 9cc
	./9cc -test
	./test.sh

clean:
	rm -f 9cc *.o *~ tmp*

.PHONY: test clean
