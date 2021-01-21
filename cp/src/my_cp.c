#include "../include/my_cp.h"
#include <unistd.h>
#include <fcntl.h>

int copy(int argc, char **argv) {
	int fdSrcFile, fdDstFile; // fd stands for file descriptor

	// check if the user entered 2 or more destinations
	// as we want source file and destination file for copying proccess
	if (argc < 3) {
		return 1;
	}

	if ((fdSrcFile = open(argv[1], O_RDONLY)) == -1) {
		// if there is an error on opening the source file
		return 2;
	}
	else if ((fdDstFile = open(argv[2], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1) {
		// if there is an error on opening the destination file
		return 3;
	}

	// array to read the content of the source file in it
	// size 2 means it takes 2 chars together then goes for the next 2 chars to them
	char buffer[1];
	ssize_t charCount; // holds the number of chars read by read() function

	// loop to write the content of source file into destination (new) file
	while ((charCount = read(fdSrcFile, buffer, sizeof(buffer))) != 0) {
		write(fdDstFile, buffer, sizeof(buffer));
	}

	return 0;
}