CFLAGS = -Wall -std=c99 -Werror -pedantic

all: app.exe test.exe

lin: app.out test.out cls

app.exe: main.o delete.o insert.o matr.o multiplication.o
	gcc -o app.exe main.o matr.o delete.o insert.o multiplication.o -lm

app.out: main.o delete.o insert.o matr.o multiplication.o
	gcc -o app.out main.o matr.o delete.o insert.o multiplication.o -lm

test.out: test.o delete.o insert.o matr.o multiplication.o
	gcc -o test.out test.o delete.o insert.o matr.o multiplication.o -lm

test.exe: test.o delete.o insert.o matr.o multiplication.o
	gcc -o test.exe test.o delete.o insert.o matr.o multiplication.o -lm

main.o: main.c
	gcc $(CFLAGS) -c main.c

delete.o: delete.c
	gcc $(CFLAGS) -c delete.c

insert.o: insert.c
	gcc $(CFLAGS) -c insert.c

matr.o: matr.c
	gcc $(CFLAGS) -c matr.c

multiplication.o: multiplication.c
	gcc $(CFLAGS) -c multiplication.c

test.o: test.c
	gcc $(CFLAGS) -c test.c

clean:
	rm -rf *.o *.exe *.out

cls:
	rm -rf *.o