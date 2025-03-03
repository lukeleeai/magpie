#include <stdio.h>

#include <string.h>

#include <stdlib.h>

//#include <math.h>

//#include <algorithm>

#include <vector>



#define MIN(a, b) ((a)>(b)? (b): (a))

#define MAX(a, b) ((a)<(b)? (b): (a))



using namespace std;



int main(int argc, char* argv[])

{

    long n;

    scanf("%ld", &n);



    vector<long> a(n);

    vector<vector<long long> > gp(n+1, vector<long long>(n+1, 0));

 

    long i, j;

    for(i=0; i<n; i++) {

        scanf("%ld", &(a[i]));

        gp[i][0] = a[i];

    }



    for(j=1; j<n; j++) {

        for(i=0; i<n-j; i++) {

            gp[i][j] = MAX(a[i]-gp[i+1][j-1], a[i+j]-gp[i][j-1]);

        }

    }

   

    printf("%lld\n", gp[0][n-1]);



    return 0;

}
