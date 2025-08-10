# main: main.c aufgabe_1.c aufgabe_2.c aufgabe_3.c
# make aufgaben
# make lib
main: main.c aufgaben lib	
	gcc main.c -o main libmy.a

aufgaben: aufgabe_1.c aufgabe_2.c aufgabe_3.c
	gcc aufgabe_1.c -c
	gcc aufgabe_2.c -c 
	gcc aufgabe_3.c -c

lib: aufgabe_1.o aufgabe_2.o aufgabe_3.o
	ar r libmy.a aufgabe_1.o aufgabe_2.o aufgabe_3.o

clean: 
	rm main aufgabe_1.o aufgabe_2.o aufgabe_3.o libmy.a