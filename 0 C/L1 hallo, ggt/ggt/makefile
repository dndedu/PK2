main: calcggt.c ggt.o # ggt.h # ggt.s
	gcc calcggt.c -o main ggt.o

calcggt_preprocessed.c: calcggt.c
	gcc -E calcggt.c -o calcggt_preprocessed.c

ggt.s: ggt.c
	gcc -S ggt.c

ggt.o: ggt.c
	gcc -c ggt.c

clean:
	rm ggt.s ggt.o main calcggt_preprocessed.c