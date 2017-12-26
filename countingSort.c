/*
 ============================================================================
 Name        : countingSort.c
 Author      : szymon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int findMax(int arr[], int arrSize){
	int max = arr[0];
	for(int i=0;i<arrSize;i++){
		max = MAX(arr[i],max);
	}
	return max;
}

void sortArr(int arr[], int arrSize, int hArr[], int max){
	int j=0;

	for(int i=0;i<max;i++){
		hArr[i] = 0;
		for(int j=0;j<arrSize;j++){
			if(i==arr[j])
				hArr[i]=hArr[i]+1;
		}
	}

	for(int i=0;i<max;i++){
		if(hArr[i]!=0){
			for(int x=0;x<hArr[i];x++){
				arr[x+j]=i;
			}
			j=hArr[i]+j;
		}
	}
}


int main(){
	int arr[] = {30,2,3,4,6,4,23,56,23,34,5,2,2,23,43,45,554,43,2365,78645,45,344,12,0,0,0,34,5};
	int arrSize = sizeof(arr)/sizeof(int);
	int max = 0;
	max = findMax(arr, arrSize)+1;

	int hArr[max];

	sortArr(&arr[0], arrSize, &hArr[0], max);

	for(int i=0;i<arrSize;i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
