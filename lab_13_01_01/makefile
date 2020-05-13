CFLAGS = -Wall -Werror -pedantic -std=c99

all: app_first.exe app_second.exe app_third.exe cls

app_first.exe: creation_first_lib
	gcc $(CFLAGS) -o app1.exe lab_08_05_1.o libstatic.a -L./ -lstatic -lm

creation_first_lib:
	gcc $(CFLAGS) -c *.c
	ar r libstatic.a array_opeations.o universal.o

app_second.exe: creation_second_lib
	gcc $(CFLAGS) -o app2.exe lab_08_05_1.o libdynamic.dll -L./ -ldynamic -lm 

creation_second_lib:
	gcc $(CFLAGS) -c -fPIC *.c
	gcc -shared -o libdynamic.dll array_opeations.o universal.o

app_third.exe: creation_third_lib
	gcc $(CFLAGS) -o app3.exe main_for_app3.o -lm

creation_third_lib:
	gcc $(CFLAGS) -c -fPIC *.c
	gcc -shared -o libdynamic.dll array_opeations.o universal.o

cls:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf *.exe
	rm -rf *.a
	rm -rf *.dll
	rm -rf *.so