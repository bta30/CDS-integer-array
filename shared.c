#include <stdio.h>

#include "shared.h"

inputData populateArr(void) {
	inputData values;
	if(scanf("%i", &(values.arrLen)) != 1)
		exitError("Unable to parse array length");
		

	values.arr = malloc(values.arrLen * sizeof(int8_t));
	if(values.arr == NULL)
		exitError("Unable to allocate space for array\n");

	for(int i = 0; i < values.arrLen; i++) {
		int input;
		if(scanf("%i", &input) != 1)
			exitError("Unable to parse array item");

		if(input < 1 || input > 4)
			exitError("Given invalid input\n");

		values.arr[i] = input;
	}

	if(scanf("%i\n%i\n%i", &values.expectedSum,
		&values.repetitions, &values.numThreads) != 3) 
		exitError("Unable to read expected sum, "
			"repetitions or number of threads");
	
	return values;
}

void exitError(const char* error) {
	fputs(error, stderr);
	exit(-1);
}

void checkSum(int sum, int expSum) {
	if(sum != expSum) {
		fprintf(stderr,
			"Got incorrect sum: Expected %i, got %i\n",
			expSum, sum);
		exit(-1);
	}

}
