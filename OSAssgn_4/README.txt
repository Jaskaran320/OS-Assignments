Here, we have made 2 syscalls: writer which inserts an element in the queue and reader which removes an element from the queue.
The queue has been implemented inside kernel space in sys.c file.
The test program implements a producer-consumer system where producer inserts an element in the queue and consumer removes an element from the queue.
This is done using mutexes and semaphores.
The mutex locks the resource while the thread is using it and then unlocks it when done.
producer function uses writer syscall to insert a random integer into the queue.
consumer function uses reader syscall to remove the integer from the queue.

How to run file:
Use make to compile the file and execute it.
Use make clean to remove the executable file.