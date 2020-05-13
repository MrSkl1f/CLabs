CFLAGS = -Wall -std=c99 -Werror -pedantic

all: app.exe test.exe cls

app.exe: main.o operationsforlist.o input.o tasks.o
	gcc -o app.exe main.o operationsforlist.o input.o tasks.o -lm

test.exe: test.o 
	gcc -o test.exe test.o 

main.o: main.c
	gcc $(CFLAGS) -c main.c

tasks.o: tasks.c
	gcc $(CFLAGS) -c tasks.c

input.o: input.c
	gcc $(CFLAGS) -c input.c

operationsforlist.o: operationsforlist.c
	gcc $(CFLAGS) -c operationsforlist.c

test.o: test.c
	gcc $(CFLAGS) -c test.c

clean:
	rm -rf *.o *.exe *.out

cls:
	rm -rf *.o