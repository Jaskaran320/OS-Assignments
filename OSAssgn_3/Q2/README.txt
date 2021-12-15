Here, I have made a struct to pass the strings as well as the ids. rand_str generates a random string of length 50 which is then passed everytime.
The for loop runs 10 times and the struct is passed to the function.
For fifo, the struct is passed to from p1 to p2. p2 prints the strings and returns the the id which is then printed in p1.
For message queue, the struct is passed from p1 to p2. p2 prints the strings and returns the the id which is then printed in p1.
For unix domain socket, p1 is client and p2 is server. p1 and p2 are first bounded to address. Then p2 listens for connection.
p1 then connects to p2 and p2 accepts the connection. Then, the struct is passed to from p1 to p2.
p2 prints the strings and returns the the id which is then printed in p1.

How to run the programs:
1. socket: make
   fifo: make fifo
   message queue: make msg
2. for unix domain socket: open split terminal first run ./p2socket in 1 terminal and then ./p1socket in another terminal. If the order is changed, the program will not work properly.
3. for fifo: open split terminal and run ./p1fifo in 1 terminal and ./p2fifo in another terminal.
4. for message queue: open split terminal and first run ./p2msg in 1 terminal and then ./p1msg in another terminal. If the order is changed, the program will not work properly.
5. make clean to remove executables.