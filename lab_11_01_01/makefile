CFLAGS = -Wall -std=c99 -Werror -pedantic

all: app.exe test.exe cls

app.exe: main.o mysnprintf.o
	gcc -o app.exe main.o mysnprintf.o

test.exe: test.o mysnprintf.o
	gcc -o test.exe test.o mysnprintf.o

mysnprintf.o: mysnprintf.c
	gcc $(CFLAGS) -c mysnprintf.c

main.o: main.c
	gcc $(CFLAGS) -c main.c

test.o: test.c
	gcc $(CFLAGS) -c test.c

cls:
	rm -rf *.o

clean:
	rm -rf *.exe