#include <stdio.h>

#include <math.h>



int main()

{

    long long int n, i, j, flag;

    scanf("%lld", &n);

    flag = n;



    for(i=1; i<=sqrt(n); i++){

        if(n%i == 0 && (i+(n/i)-2)<flag)

            flag = i+(n/i)-2;

    }

    printf("%lld", flag);

    return 0;

}
