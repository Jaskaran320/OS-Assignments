How to run makefile

make --> compile both files and execute them. This gives final output.
To run step by step:

make preprocess --> preprocess both files
make compile --> compile both files
make assemble --> assemble both files
make link --> generate executable files and execute them

make clean --> delete all intermediary and executable files.

Explanation for file 1a

data() is called in the start which opens student_record.csv
If this gives error then perror prints the error.
Now all data in the csv file is read into "ch" buffer.
Then this data is broken line by line into tokens using strtok() and stored in lines[].
Then for every line data is broken into tokens through ',' delimiter.
The tokens are in string format so they are type casted into int using atoi() then stored into appropriate arrays and file is closed.
Then the fork() command is called. 
The command then goes to parent where waitpid is called which forces parent to wait till child process is finished.
The child function then executes.
The averages of the students who are in section A are printed into written_records1.txt
Then the parent process runs.
The averages of the students who are in section B are printed into written_records1.txt
END

Explanation for file 1b

2 threads are created tid, tid1.
tid and tid1 call data() which processes student_record.csv and stores data into appropriate arrays.
Then pthread_join() ensures that tid1 is stopped until tid finishes.
Then the averages of the students who are in section A are printed into written_records2.txt
And then the averages of the students who are in section B are printed into written_records2.txt
Then assign_avg() is called which calculates average for each assignment.
This data is then printed into written_records2.txt
END

open syscall --> open file, O_RDONLY opens it in readonly mode. Assigns value of file descriptor to int.
read syscall --> read file, takes input of file descriptor, buffer to store data and length of buffer.
write syscall --> write into file, takes input 