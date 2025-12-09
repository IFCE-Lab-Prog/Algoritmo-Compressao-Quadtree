gcc -c pgm/pgm.c
gcc -c src/binHeader.c
gcc -c src/bitstream.c
gcc -c src/compress.c
gcc -c src/util.c
gcc -c src/encoder.c

gcc -o encoder.exe encoder.o binHeader.o bitstream.o compress.o util.o pgm.o -lm

gcc -c src/decoder.c
gcc -c src/bitstream_dec.c
gcc -c src/quadtree_dec.c
gcc -c src/pgm_dec.c

gcc -o decoder.exe decoder.o bitstream_dec.o quadtree_dec.o pgm_dec.o