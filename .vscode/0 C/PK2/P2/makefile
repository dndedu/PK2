main: main.c char_utility.o queue.o
	gcc main.c -o main char_utility.o queue.o

charUtils.o: char_utility.c
	gcc -c char_utility.c

queue.o: queue.c
	gcc -c queue.c

clean:
	rm *.o main