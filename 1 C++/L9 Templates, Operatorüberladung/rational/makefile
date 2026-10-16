main: main.cpp rational.o
	g++ main.cpp -o main rational.o

rational.o: rational.cpp
	g++ rational.cpp -c

clean:
	rm main rational.o