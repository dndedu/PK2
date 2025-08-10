main: main.cpp vector.o
	g++ main.cpp -o main vector.o -std=c++11

vector.o: vector.cpp
	g++ vector.cpp -c -std=c++11

clean:
	rm main vector.o