# CP Command Implementaion  
basic implemenation of the linux cp command that copies file from one destination to another  

## Compiling
First Way:
1. go to ***bin*** directory  
2. excute the ***Makefile*** to get the excutable  
3. run the program, having two pathes (one you want to copy, the other one the path you want to copy to), let's say you have a source.txt file and you want to copy it into current directory: 
```bash
./my_cp source.txt destination.txt
```

second way:
1. go to **src** directory
2. compile the program using [gcc](https://www.geeksforgeeks.org/gcc-command-in-linux-with-examples/)
```bash
gcc main.c -o my_cp
```
3. run the program, having two pathes (one you want to copy, the other one the path you want to copy to), let's say you have a source.txt file and you want to copy it into current directory: 
```bash
./my_cp source.txt destination.txt
```
