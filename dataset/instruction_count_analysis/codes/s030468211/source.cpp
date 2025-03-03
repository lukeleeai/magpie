#include<stdio.h>

#include<limits.h>



int main(void) {

    int i, j, k;

    int wholeFlag = 0;

    int N, M, X;

    int mini = INT_MAX;

    int C[100000];

    int A[100000][12];

    scanf("%d %d %d", &N, &M, &X);

    for(i = 0;i < N;i++) {

        scanf("%d", &C[i]);

        for(j = 0;j < M;j++) scanf("%d", &A[i][j]);

    }

    for(i = 0;i < 1LL << N;i++) {

        int money = 0;

        int flag = 1;

        int rikai[12] = {};

        for(j = 0;j < N;j++) {

            if(i & (1LL << j)) {

                money += C[j];

                for(k = 0;k < M;k++) rikai[k] += A[j][k];

            }

        }

        for(j = 0;j < M;j++) {

            if(rikai[j] < X) flag = 0;

        }

        if(flag) {

            wholeFlag = 1;

            mini = mini < money ? mini : money;

        }

    }

    if(wholeFlag) printf("%d\n", mini);

    else puts("-1");

    return 0;

}
