all: main clear

main: main.o menu.o random.o metric.o file.o quicksort.o selectionsort.o vectorbook.o vectortext.o vectorword.o linkedbook.o linkedtext.o linkedword.o
	gcc main.o menu.o random.o metric.o file.o quicksort.o selectionsort.o vectorbook.o vectortext.o vectorword.o linkedbook.o linkedtext.o linkedword.o

main.o: main.c
	gcc -c main.c -o main.o

file.o: libinterface/file.c
	gcc -c libinterface/file.c -o file.o

menu.o: libinterface/menu.c
	gcc -c libinterface/menu.c -o menu.o

random.o: libinterface/random.c
	gcc -c libinterface/random.c -o random.o

metric.o: libmetric/metric.c
	gcc -c libmetric/metric.c -o metric.o

quicksort.o: libsorting/quicksort.c
	gcc -c libsorting/quicksort.c -o quicksort.o

selectionsort.o: libsorting/selectionSort.c
	gcc -c libsorting/selectionSort.c -o selectionsort.o

vectorbook.o: libvector/vectorbook.c
	gcc -c libvector/vectorbook.c -o vectorbook.o

vectortext.o: libvector/vectortext.c
	gcc -c libvector/vectortext.c -o vectortext.o

vectorword.o: libvector/vectorword.c
	gcc -c libvector/vectorword.c -o vectorword.o

linkedbook.o: liblinked/linkedbook.c
	gcc -c liblinked/linkedbook.c -o linkedbook.o

linkedtext.o: liblinked/linkedtext.c
	gcc -c liblinked/linkedtext.c -o linkedtext.o

linkedword.o: liblinked/linkedword.c
	gcc -c liblinked/linkedword.c -o linkedword.o

clear:
  rm *.o
	# del *.o
