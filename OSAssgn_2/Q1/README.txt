In this program, q1.c is the main program.
It calls fork() 2 times. The first forked process calls the handler function using sigaction struct.
Then the parent calls another fork() to create another child process.
The second child process uses execvp syscall to execute E1 and pass the pid of the first process to E1.
The parent process then uses execvp syscall to execute E2 and pass the pid of the first process to E2.
In E1, struct itimerval is used to set the timer for the handler function and the signal is set to SIGALRM.
infinite while loop is used to keep the parent process alive.
handler1 is called which then calls rdrand to generate a random number and and uses sigqueue to send this to handler function to print it.
Similarly, when E2 is executed, struct itimerval is used to set the timer for the handler function and the signal is set to SIGALRM.
infinite while loop is used to keep the parent process alive.
handler2 is called which then uses rdtsc to get the current time and and uses sigqueue to send this to handler function to print it.
This continues until the user sends SIGINT(ctrl+c) to terminate the program.

How to run the program:

use make to compile the program and execute it and use ctrl+c to terminate the program.
use make clean to remove the executable files.