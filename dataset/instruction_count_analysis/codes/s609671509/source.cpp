#include <stdio.h>

#include <math.h>

#define MAX_N 10000

#define MAX_k 9

int N, k;

int D[MAX_k];

int check(int a){

    int i, j, n, m;

n=a;

while(n!=0){

        m = n%10;

        for (j=0; j<k; j++)

            if (m==D[j]) return 1;

            n/=10;

}

    return 0;

}

int main(){

    int i;

    scanf("%d%d", &N, &k);

    for (i=0; i<k; i++)

        scanf("%d", &D[i]);

    i=N;

    while (1)

    {

        if(check(i)==0)break;

        else

        {

            i++;

        }

    }

    printf("%d\n", i);

    return 0;

}
