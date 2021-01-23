#include "../include/my_cp.h"
#include <stdio.h>
#include <stdlib.h>

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
    dstFilePtr = fopen(argv[2], "wb+");

    char *buff; // array to store the data of source file
    long long numbytes; // variable to store the number of bytes of source's file data

    // Get the number of bytes that the source file contains
    fseek(srcFilePtr, 0L, SEEK_END);
    numbytes = ftell(srcFilePtr);

    // reset the file position indicator to the beginning of the file
    fseek(srcFilePtr, 0L, SEEK_SET);

    // grab sufficient memory for the buffer to hold the text
    buff = (char *) calloc(numbytes, sizeof(char));

    // memory error
    if (buff == NULL)
        return 3;

    // copy all the binary into the buffer from the source file
    fread(buff, sizeof(char), numbytes, srcFilePtr);
    // write all the binary into the distination file from the buffer
    fwrite(buff, sizeof(char), numbytes, dstFilePtr);


    // close the files
    fclose(srcFilePtr);
    fclose(dstFilePtr);
    return 0;
}