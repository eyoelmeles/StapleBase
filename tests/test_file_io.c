#include "../file_io.h"
#include <stdio.h>

int main() {
    // Test writeIntegersToFile and readIntegersFromFile functions
    int integers[] = {1, 2, 3, 4, 5};
    int numIntegers = sizeof(integers) / sizeof(int);
    writeIntegersToFile("test_integers.bin", integers, numIntegers);

    int* readIntegers = readIntegersFromFile("test_integers.bin", &numIntegers);
    if (readIntegers != NULL && numIntegers == 5) {
        int passed = 1;
        for (int i = 0; i < numIntegers; i++) {
            if (readIntegers[i] != integers[i]) {
                passed = 0;
                break;
            }
        }
        if (passed) {
            printf("writeIntegersToFile and readIntegersFromFile: Passed\n");
        } else {
            printf("writeIntegersToFile and readIntegersFromFile: Failed\n");
        }
        free(readIntegers);
    } else {
        printf("writeIntegersToFile and readIntegersFromFile: Failed\n");
    }

    return 0;
}

