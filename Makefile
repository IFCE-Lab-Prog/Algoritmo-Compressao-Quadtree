all: encoder.e

encoder.e: encoder.o binHeader.o bitstream.o compress.o util.o pgm.o
	gcc -o encoder.e encoder.o binHeader.o bitstream.o compress.o util.o pgm.o -lm

pgm.o: pgm/pgm.c
	gcc -c pgm/pgm.c

binHeader.o: src/binHeader.c
	gcc -c src/binHeader.c

bitstream.o: src/bitstream.c
	gcc -c src/bitstream.c

compress.o: src/compress.c
	gcc -c src/compress.c

util.o: src/util.c
	gcc -c src/util.c

encoder.o: src/encoder.c
	gcc -c src/encoder.c

clean:
	rm -f *.o encoder.e