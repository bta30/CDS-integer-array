#include <pthread.h>

#include "shared.h"

void *calcSum(void *data) {
	threadData *info = data;
	int sum = 0;
	int8_t *arrStart = info->arrStart;
	int8_t *arrEnd = info->arrEnd;
	
	for(; arrStart < arrEnd; arrStart++)
		sum += (*arrStart) * (*arrStart);
	
	*(info->sum) = sum;
	return NULL;
}

void threadTest(inputData values) {
	pthread_t threads[values.numThreads];
	int threadSums[values.numThreads];
	threadData info[values.numThreads];

	int arrStep = values.arrLen / values.numThreads;
	int8_t *arrStart = values.arr;
	int8_t *arrEnd = arrStart + arrStep;

	for(int i = 0; i < values.numThreads; i++) {
		if(i == values.numThreads - 1) {
			arrEnd = values.arr + values.arrLen;
		}
		info[i] = (threadData){threadSums + i, arrStart, arrEnd};
		pthread_create(threads + i, NULL, calcSum, info + i);

		arrStart += arrStep;
		arrEnd += arrStep;
	}
	
	int totalSum = 0;
	for(int i = 0; i < values.numThreads; i++) {
		pthread_join(threads[i], NULL);
		totalSum += threadSums[i];
	}

	checkSum(totalSum, values.expectedSum);
}

int main(void) {
	inputData values = populateArr();

	for(int i = 0; i < values.repetitions; i++)
		threadTest(values);
	
	free(values.arr);
	return 0;
}
