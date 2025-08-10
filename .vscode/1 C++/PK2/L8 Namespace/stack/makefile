main: main.cpp stack.o
	c++ main.cpp -o main stack.o -std=c++11

stack.o: stack.cpp
	c++ stack.cpp -c -std=c++11

clean:
	rm main stack.o