#include <stdio.h>

#include "shared.h"

void compSum(inputData values) {
	int sum = 0;
	for(int i = 0; i < values.arrLen; i++) {
		sum += values.arr[i] * values.arr[i];
	}

	checkSum(sum, values.expectedSum);
}

int main(void) {
	inputData values = populateArr();

	for(int i = 0; i < values.repetitions; i++)
		compSum(values);
	
	free(values.arr);
	return 0;
}
