#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>

// Function to write an array of integers to a binary file
int writeIntegersToFile(const char* filename, int* integers, int numIntegers) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file %s for writing\n", filename);
        return -1;
    }

    fwrite(integers, sizeof(int), numIntegers, file);
    fclose(file);

    return 0;
}

// Function to read an array of integers from a binary file
int* readIntegersFromFile(const char* filename, int* numIntegers) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file %s for reading\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *numIntegers = fileSize / sizeof(int);
    int* integers = (int*)malloc(fileSize);
    if (integers == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fread(integers, sizeof(int), *numIntegers, file);
    fclose(file);

    return integers;
}

