#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <string>

#include <cmath>

#include <cstdlib>

using namespace std;



const int MAX = 500010;

int n;

int a[MAX];

int tmp[MAX];

int com;



void merge(int A[], int lo, int mi, int hi) {

    int p1 = lo;

    int p2 = mi;

    int p3 = lo;

    while (p1 < mi && p2 < hi) {

        com++;

        if (A[p1] <= A[p2]) {

            tmp[p3++] = A[p1++];

        } else {

            tmp[p3++] = A[p2++];

        }

    }

    while (p1 < mi) {tmp[p3++] = A[p1++]; com++;}

    while (p2 < hi) {tmp[p3++] = A[p2++]; com++;}

    for (int i = lo; i < hi; i++) {

        A[i] = tmp[i];

    }

}



void mergeSort(int A[], int lo, int hi) {

    if (lo + 1 < hi) {

        int mi = (lo + hi) >> 1;

        mergeSort(A, lo, mi);

        mergeSort(A, mi, hi);

        merge(A, lo, mi, hi);

    }

}





int main() {

    //freopen("in.txt", "r", stdin);

    //freopen("out.txt", "w", stdout);

    scanf("%d", &n);

    com = 0;

    for (int i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }

    mergeSort(a, 0, n);

    for (int i = 0; i < n; i++) {

        if (i > 0) printf(" ");

        printf("%d", a[i]);

    }

    printf("\n");

    printf("%d\n", com);

    return 0;

}