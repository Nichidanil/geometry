.PHONY: all clean

all: bin/geometry


bin/geometry: build/src/main.o build/src/circle.o
	gcc -Wall -Werror build/src/main.o build/src/circle.o -o bin/geometry -lm

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/circle.o: src/crcl.c
	gcc -Wall -Werror -c src/crcl.c -o build/src/circle.o

test: bin/test

bin/test: build/test/main.o build/test/circle.o
	gcc -Wall -Werror build/test/main.o build/test/circle.o -o bin/test -lm

build/test/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o build/test/main.o

build/test/circle.o: src/crcl.c src/crcl.h
	gcc -Wall -Werror -c -I thirdparty -I src src/crcl.c -o build/test/circle.o

clean:
	rm -rf build/src/*.o bin/geometry
	rm -rf build/test/*.o bin/test