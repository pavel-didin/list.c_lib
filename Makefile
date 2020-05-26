CC=gcc
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.c
	${CC} -c tests.c -o tests.o ${CFLAGS}
list.o: list.c
	${CC} -c list.c -o list.o ${CFLAGS}
tests: tests.o list.o
	${CC} list.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../list.tgz ../list
