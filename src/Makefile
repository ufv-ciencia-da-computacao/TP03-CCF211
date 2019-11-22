all: main clear

main: main.o linkedtext.o linkedword.o
	gcc main.o linkedtext.o linkedword.o -o main

main.o: main.c
	gcc -c main.c -o main.o

linkedtext.o: liblinked/linkedtext.c
	gcc -c liblinked/linkedtext.c -o linkedtext.o

linkedword.o: liblinked/linkedword.c
	gcc -c liblinked/linkedword.c -o linkedword.o

clear:
	del *.o
