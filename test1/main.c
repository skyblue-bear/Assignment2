#include <stdio.h>
#include <malloc.h>

int main()
{
	int size;
	int *input;
	int *temp;
	int max;
	int i;

	scanf("%d", &size);

	input = (int *)malloc(sizeof(int) * size);
	temp = (int *)malloc(sizeof(int) * size);

	for(i = 0; i<size; i++){
		scanf("%d", &input[i]);
		temp[i] = input[i];
	}

	max = input[0];
	for(i = 1; i<size; i++){
		if(input[i] <= temp[i-1] + input[i]){
			temp[i] = temp[i-1] + input[i];
		}
		if(max < temp[i]){
			max = temp[i];
		}
	}

	printf("array's continuous sub set maximum value is %d\n", max);
	printf("conflict test\n");

	return 0;
}
