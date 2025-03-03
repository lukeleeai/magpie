#include <stdio.h>

#include <algorithm>

using namespace std;



int main()

{

    long long n, m;

    scanf("%lld %lld", &n, &m);

    if(n == 2 || m == 2) printf("0");

    else if(min(n, m) == 1){

        int maximum = max(n, m);

        printf("%lld", maximum == 1 ? 1 : maximum - 2);

    } else 

        printf("%lld", (m-2)*(n-2));

    

    return 0;

}