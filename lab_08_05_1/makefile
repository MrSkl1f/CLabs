CFLAGS = -Wall -Werror -pedantic

all: app.exe test.exe

app.exe: lab_08_05_1.o array_opeations.o universal.o
	gcc -o app.exe lab_08_05_1.o array_opeations.o universal.o

test.exe: test.o array_opeations.o universal.o
	gcc -o test.exe test.o array_opeations.o universal.o

lab_08_05_1.o: lab_08_05_1.c
	gcc $(CFLAGS) -c lab_08_05_1.c

array_opeations.o: array_opeations.c
	gcc $(CFLAGS) -c array_opeations.c

universal.o: universal.c
	gcc $(CFLAGS) -c universal.c

test.o: test.c
	gcc $(CFLAGS) -c test.c

clean:
	rm *.o
	rm *.exe