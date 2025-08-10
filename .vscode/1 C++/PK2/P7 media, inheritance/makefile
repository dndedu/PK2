main: main.cpp Medium.o Audio.o Bild.o
	g++ main.cpp -o main Medium.o Audio.o Bild.o -std=c++11

Medium.o: Medium.cpp
	g++ Medium.cpp -c -std=c++11
	
Audio.o: Audio.cpp
	g++ Audio.cpp -c -std=c++11

Bild.o: Bild.cpp
	g++ Bild.cpp -c -std=c++11

clean:
	rm main Medium.o Audio.o Bild.o