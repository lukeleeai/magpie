#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

//#include <algorithm>

#include <vector>

 

int main(int argc, char* argv[])

{

    long n, m, q;

    scanf("%ld %ld %ld", &n, &m, &q);



    long x[501][501]={0};



    std::vector<long> a(2*m);

    std::vector<long> p(2*q);

    long i, j;

    for(i=0; i<m; i++) {

        scanf("%ld %ld", &(a[2*i]), &(a[2*i+1]));

        x[a[2*i]][a[2*i+1]] ++;

    }

    for(i=1; i<=500; i++) {

        for(j=2; j<=500; j++) {

            x[i][j] += x[i][j-1];

        }

    }



    for(i=0; i<q; i++) {

        scanf("%ld %ld", &(p[2*i]), &(p[2*i+1]));

    }



    for(i=0; i<q; i++) {

        long num = 0;

        long k;

        for(k=p[2*i]; k<=p[2*i+1]; k++) {

            num += (x[k][p[2*i+1]] - x[k][p[2*i]-1]);

        }

        printf("%d\n", num);

    }



    return 0;

}
