#include <stdio.h>

 

int num[50];

int main()

{

    int n;

    scanf("%d",&n);

    int cnt=0;

     if(n==0){

        printf("0\n");

        return 0;

    }

    while(n){

        if(n%2!=0){

            num[++cnt]=1;

            n=(n-1)/(-2);

        }else{

            num[++cnt]=0;

            n=n/(-2);

        }

    }

 

    for(int i=cnt;i>=1;i--)

        printf("%d",num[i]);

}