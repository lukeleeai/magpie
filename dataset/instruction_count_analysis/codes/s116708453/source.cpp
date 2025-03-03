/*

#include<iostream>

using namespace std;



int A[2000005], B[2000005], C[10005];



void CountingSort(int n) {

    int k = 10000;

    for (int i = 0; i <= k; i++) C[i] = 0;



    for (int j = 0; j < n; j++) C[A[j]]++;



    for (int i = 1; i <= k; i++) C[i] += C[i - 1];



    for (int j = n - 1; j >= 0; j--) {

        B[C[A[j]] - 1] = A[j];

        C[A[j]]--;

    } 

}



int main() {

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    CountingSort(n);

    for (int i = 0; i < n; i++) cout << B[i] << (i != n - 1 ? " " : "\n");

}

*/



#include<stdio.h>

#include<stdlib.h>

#define MAX 2000001

#define VMAX 10000



int main() {

    unsigned short *A, *B;



    int C[VMAX + 1];

    int n, i, j;

    scanf("%d", &n);



    A = (unsigned short *)malloc(sizeof(unsigned short) * (n + 1));

    B = (unsigned short *)malloc(sizeof(unsigned short) * (n + 1));



    for (i = 0; i <= VMAX; i++) C[i] = 0;



    for (i = 0; i < n; i++) {

        scanf("%hu", &A[i + 1]);

        C[A[i + 1]]++;

    }



    for (i = 1; i <= VMAX; i++) C[i] = C[i] + C[i - 1];



    for (j = 1; j <= n; j++) {

        B[C[A[j]]] = A[j];

        C[A[j]]--; 

    }



    for (i = 1; i <= n; i++) {

        if (i > 1) printf(" ");

        printf("%d", B[i]);

    }

    printf("\n");



    return 0;

}
