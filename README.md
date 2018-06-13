# Rushes
Rush is a small (2 day time) project at UNITFactory (school 42)

For now i completed 4 of them:

## minitalk

task was to create kind of client-server chat. Actually client is one process,
server is another one. They are exhanging messages via 2 signals. One is
1 bit, another is 0 bit. Then they are composed to original string and printed.

````bash
make
./server
server_pid == <process_id>
Client usage:
Usage: client <server_pid> <message>
For ex:
./client 9000 'Hello!'
````
![alt text](https://github.com/DA-NDI/Rushes-group-projects-/blob/master/Screenshots/minitalk_1.png)

![alt text](https://github.com/DA-NDI/Rushes-group-projects-/blob/master/Screenshots/minitalk_2.png)

## puissance

puissance task was to create game "4 in a row". Both AI and input.

AI tries to win.

Usage: ./Power\ 4 <width of a grid> <height of a grid>
````bash
make
./Power\ 4 7 7
````

![alt text](![alt text](https://github.com/DA-NDI/Rushes-group-projects-/blob/master/Screenshots/power_1.png))

## hotrace

implementation of very quick read and search. Hashtables (using jenkins alghorithm for hashing)

Got highest mark (mark depends on how quick your  programm performs)

![alt text](![alt text](https://github.com/DA-NDI/Rushes-group-projects-/blob/master/Screenshots/hotrace.png))

## lldb

configuration of lldb debugger, creating useful functions (in python) and automatization.

![alt text](https://github.com/DA-NDI/Rushes-group-projects-/blob/master/Screenshots/lldb.png)

All tasks and corrections you can find in project's repo's.


