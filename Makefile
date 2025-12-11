all: encoder.e decoder.e

encoder.e: encoder.o pgm.o bitstream.o compress.o util.o
	gcc -o encoder.e encoder.o bitstream.o compress.o util.o pgm.o -lm

encoder.o: src/encoder.c
	gcc -c src/encoder.c

pgm.o: pgm/pgm.c
	gcc -c pgm/pgm.c

bitstream.o: src/bitstream.c
	gcc -c src/bitstream.c

compress.o: src/compress.c
	gcc -c src/compress.c

util.o: src/util.c
	gcc -c src/util.c

decoder.e: decoder.o bitstream_dec.o quadtree_dec.o pgm_dec.o
	gcc -o decoder.e decoder.o bitstream_dec.o quadtree_dec.o pgm_dec.o

decoder.o: src/decoder.c
	gcc -c src/decoder.c

bitstream_dec.o: src/bitstream_dec.c
	gcc -c src/bitstream_dec.c

quadtree_dec.o: src/quadtree_dec.c
	gcc -c src/quadtree_dec.c

pgm_dec.o: src/pgm_dec.c
	gcc -c src/pgm_dec.c

clean:
	rm -f *.o encoder.e decoder.e