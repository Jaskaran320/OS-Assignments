In this program, we are changing the vruntime using the struct of sched_entity by adding the delay which is taken from the user.
We have created a struct for the process whose vruntime is to be changed.
test.c is used to test the program.
A function has been created in sys.c and the diff is taken into syspatch.patch file.
How to run the syscall:
1. make to compile the program and execute it.
2. make clean to remove the executables.