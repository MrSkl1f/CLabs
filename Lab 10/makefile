CFLAGS = -Wall -std=c99 -Werror -pedantic

all: app.exe test.exe cls

app.exe: structure.o main.o addmark.o sort.o birthday.o delete.o
	gcc -o app.exe structure.o addmark.o sort.o birthday.o delete.o main.o -lm

test.exe: test.o structure.o addmark.o sort.o birthday.o delete.o
	gcc -o test.exe test.o structure.o addmark.o sort.o birthday.o delete.o 

test.o: test.c
	gcc $(CFLAGS) -c test.c

structure.o: structure.c
	gcc $(CFLAGS) -c structure.c

main.o: main.c
	gcc $(CFLAGS) -c main.c

addmark.o: addmark.c
	gcc $(CFLAGS) -c addmark.c

sort.o: sort.c
	gcc $(CFLAGS) -c sort.c

birthday.o: birthday.c
	gcc $(CFLAGS) -c birthday.c

delete.o: delete.c
	gcc $(CFLAGS) -c delete.c

cls:
	rm -rf *.o *.out

clean:
	rm -rf *.o *.exe