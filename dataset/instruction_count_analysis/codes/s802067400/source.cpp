#include <stdio.h>

#include <string.h>

 

int main()

{

    long long n;

    scanf("%lld",&n);

    char x[100]={0};

    int i=0;

    n--;

    while(n>=0){

        x[i]=n%26+'a';

        n/=26;

        i++;

        n--;

    }

    for(int j=i-1;j>=0;j--){

        printf("%c",x[j]);

    }

    return 0;

}