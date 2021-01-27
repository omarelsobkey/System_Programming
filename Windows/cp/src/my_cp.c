#include "../include/my_cp.h"
#include <stdio.h>

int copy(int argc, char **argv) {
    FILE *srcFilePtr, *dstFilePtr;

    // check that there is a source and distination files at least
    if (argc < 3) {
        return 1;
    }

    // open the source file for reading the binaries of it
    if ((srcFilePtr = fopen(argv[1], "rb")) == NULL) {
        return 2;
    }

    // open the destination file for both reading and writing the binaries
	if ((dstFilePtr = fopen(argv[2], "wb+")) == NULL) {
        return 3;
    }

    char buff[10]; // array to store the data of source file
    int count; // stores the number of digits read by the fread() function

    // copy all the binary into the buffer from the source file and writes it to the distination file
    while((count = fread(buff, sizeof(char), 10, srcFilePtr)) != 0){
    	fwrite(buff, sizeof(char), count, dstFilePtr);
    }    

    // close the files
    fclose(srcFilePtr);
    fclose(dstFilePtr);
    return 0;
}