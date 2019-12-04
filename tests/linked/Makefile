all: main clear

main: main.o linkedword.o linkedtext.o linkedbook.o
	gcc main.o linkedword.o linkedtext.o linkedbook.o -o main

main.o: main.c
	gcc -c main.c -o main.o

linkedbook.o: ../../src/liblinked/linkedbook.c
	gcc -c ../../src/liblinked/linkedbook.c -o linkedbook.o

linkedtext.o: ../../src/liblinked/linkedtext.c
	gcc -c ../../src/liblinked/linkedtext.c -o linkedtext.o

linkedword.o: ../../src/liblinked/linkedword.c
	gcc -c ../../src/liblinked/linkedword.c -o linkedword.o

clear:
	# del *.o
	rm *.o
