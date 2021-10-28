default:
	nasm -f elf64 -o b.o b.asm
	gcc a.c -o a.o
	gcc c.c -o c.o
	gcc -no-pie a.o b.o c.o -o run
	./run

clean:
	rm -f run a.o b.o c.o