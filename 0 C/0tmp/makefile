main: main.c utilities.o utilities.h
	gcc main.c -o main utilities.o utilities.h

utilities.o: utilities.c
	gcc utilities.c -c

clean:
	rm main utilities.o