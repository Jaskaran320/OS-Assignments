Here, we have used semaphores to handle the racce condition which arises in the dining philosophers problem.

In the 1st part, we have used the semaphores to handle the condition of the forks.
The philosophers are waiting for 2 forks adjacent to them to be available.
To prevent deadlock, we have used the semaphores to handle the condition of the forks.

In the 2nd part, there is no deadlock as there are 4 bowls and only 1 fork is needed to eat.
So, each philosopher can eat when the bowl is available and hence, 4 philosophers can eat at the same time.
When the bowls are freed, the philosophers can then use them to eat.

In the 3rd part, the deadlock has been handled by using the semaphores for the forks and the bowls.
The philosophers are waiting for 2 forks and the bowls to be available.
To prevent deadlock, we have used the semaphores to handle the condition of the forks and the bowls.

How to run the files:
Use make to compile the files and then execute them.
Use make clean to remove the executable files.