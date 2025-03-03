#include<stdio.h>

#define MAX 500000

#define INFTY 2000000000



int L[MAX / 2 + 1], R[MAX / 2 + 1];

int A[MAX];

int cnt = 0;



void merge(int A[], int left, int mid, int right){

	int i,j;

	int n1 = mid - left;

	int n2 = right - mid;

	for (i = 0; i < n1; i++){

		L[i] = A[left+i];

	}

	for (i = 0; i < n2; i++){

		R[i] = A[mid+i];

	}

	L[n1] = R[n2] = INFTY;

        i=0;

        j=0;

	for (int k = left; k < right; k++){

		cnt++;

		if (L[i] <= R[j]){

			A[k] = L[i++];

		}

		else{

			A[k] = R[j++];

		}

	}

}



void mergeSort(int A[], int left, int right){

	if (left + 1 < right){

		int mid = (left + right) / 2;

		mergeSort(A, left, mid);

		mergeSort(A, mid, right);

		merge(A, left, mid, right);

	}

}



int main(){

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++){

		scanf("%d", &A[i]);

	}

	mergeSort(A, 0, n);

	for (int i = 0; i < n; i++){

		if (i)printf(" ");

		printf("%d", A[i]);

	}

	printf("\n");

        printf("%d\n",cnt);

	return 0;

}