#ifndef FILE_IO_H
#define FILE_IO_H

// Function declarations
int writeIntegersToFile(const char* filename, int* integers, int numIntegers);
int* readIntegersFromFile(const char* filename, int* numIntegers);

#endif /* FILE_IO_H */

