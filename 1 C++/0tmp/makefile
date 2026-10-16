main: main.cpp utilities.o utilities.h student.o student.h simple.h simple.o
	g++ main.cpp -o main utilities.o student.o simple.o

simple.o: simple.cpp simple.h
	g++ simple.cpp -c

student.o: student.cpp student.h
	g++ student.cpp -c

utilities.o: utilities.cpp utilities.h
	g++ utilities.cpp -c

clean:
	rm main simple.o student.o utilities.o