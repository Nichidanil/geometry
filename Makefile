all: geometry


geometry: main.o circle.o
	gcc -Wall -Werror build/main.o build/circle.o -o bin/geometry

main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

circle.o: src/crcl.c
	gcc -Wall -Werror -c src/crcl.c -o build/circle.o
clean:
	rm -rf build/*.o bin/geometry