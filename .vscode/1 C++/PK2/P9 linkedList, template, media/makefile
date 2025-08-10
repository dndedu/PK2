CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

all: main

main: main.cpp linkedList.o medium.o audio.o bild.o
	$(CXX) $(CXXFLAGS) main.cpp linkedList.o medium.o audio.o bild.o -o main

linkedList.o: linkedList.cpp linkedList.h iterator.h
	$(CXX) $(CXXFLAGS) -c linkedList.cpp -o linkedList.o

medium.o: medium.cpp medium.h
	$(CXX) $(CXXFLAGS) -c medium.cpp -o medium.o

audio.o: audio.cpp audio.h medium.h
	$(CXX) $(CXXFLAGS) -c audio.cpp -o audio.o

bild.o: bild.cpp bild.h medium.h
	$(CXX) $(CXXFLAGS) -c bild.cpp -o bild.o

clean:
	rm -f main *.o