all: main clear

main: main.o vectorbook.o vectortext.o vectorword.o
	gcc main.o vectorbook.o vectortext.o vectorword.o -o main

main.o: main.c
	gcc -c main.c -o main.o

vectorbook.o: ../../libvector/vectorbook.c
	gcc -c ../../libvector/vectorbook.c -o vectorbook.o

vectortext.o: ../../libvector/vectortext.c
	gcc -c ../../libvector/vectortext.c -o vectortext.o

vectorword.o: ../../libvector/vectorword.c
	gcc -c ../../libvector/vectorword.c -o vectorword.o

clear:
	del *.o
