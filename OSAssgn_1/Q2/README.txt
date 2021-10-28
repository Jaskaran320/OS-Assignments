How to run makefile

make --> compile both files and execute them. This gives final output.
make clean --> delete all intermediary and executable files.

On compiling the program, first the main in a.c is executed.
This prints output --> "in main of a"
Then void a function is executed.
This prints output --> "in a()" and takes input of 64 bit int.
Then it passes this int and calls b.ass
This prints output --> "in b()" 
The int is converted to 8 byte ASCII by compiler.
extern c in the start adds c.c to the file environment
[rbp+8] ensures that ret of stack calls c.
Flow of program is a.c --> main --> a() --> b.asm --> c.c