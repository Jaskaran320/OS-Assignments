default:
	gcc 1a.c -o 1a
	gcc 1b.c -o 1b -pthread
	./1a
	./1b

preprocess:
	gcc -E 1a.c -o 1a.i
	gcc -E 1b.c -o 1b.i -pthread

compile: 
	gcc -S 1a.i -o 1a.s
	gcc -S 1b.i -o 1b.s -pthread

assemble:
	gcc -c 1a.s -o 1a.o
	gcc -c 1b.s -o 1b.o -pthread

link:
	gcc 1a.o -o 1a
	gcc 1b.o -o 1b -pthread
	./1a
	./1b

clean:
	rm -f 1a 1b 1a.i 1b.i 1a.s 1b.s 1a.o 1b.o