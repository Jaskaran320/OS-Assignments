In this program, I have made a syscall to print a 2D floating-point matrix to another.
To do this I have used copy_from_user and copy_to_user functions.
I have passed 2 matrices to syscall, one with the data(arr) and one which is empty(arr1).
Then I created another empty matrix(arr2) inside the syscall and kernel space.
Then I copied the data from arr to arr2.
Then I copied the data from arr2 to arr1.
The test program sends the calls the syscall and prints the data of arr1.
So, the data of arr1 is the same as the data of arr.
The data of arr is present in user space and arr2 is present in kernel space.
And after copying the data into arr1 from arr2, it goes back into user space.

How to run the program:

use make to compile the program and execute it.
use make clean to remove the executable file.