#ifndef SHARED_H
#define SHARED_H

#include <stdlib.h>

typedef struct {
	int arrLen;
	int8_t *arr;

	int expectedSum;
	int repetitions;
	int numThreads;
} inputData;

typedef struct {
	int *sum;
	int8_t *arrStart, *arrEnd;
} threadData;

extern inputData populateArr(void);
extern void exitError(const char* error);
extern void checkSum(int sum, int expSum);

#endif
