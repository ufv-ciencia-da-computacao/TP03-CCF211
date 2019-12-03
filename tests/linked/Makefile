all: main clear

main: main.o test.o linkedbook.o linkedtext.o linkedword.o
	gcc main.o test.o linkedbook.o linkedtext.o linkedword.o -o main

main.o: main.c
	gcc -c main.c -o main.o

test.o: ../../libtest/test.c
	gcc -c ../../libtest/test.c -o test.o

linkedbook.o: ../../liblinked/linkedbook.c
	gcc -c ../../liblinked/linkedbook.c -o linkedbook.o

linkedtext.o: ../../liblinked/linkedtext.c
	gcc -c ../../liblinked/linkedtext.c -o linkedtext.o

linkedword.o: ../../liblinked/linkedword.c
	gcc -c ../../liblinked/linkedword.c -o linkedword.o

clear:
	del *.o
