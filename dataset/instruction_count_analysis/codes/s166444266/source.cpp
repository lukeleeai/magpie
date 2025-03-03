#include<stdio.h>

int main() { 

    int i,n,x,rem,cnt,flag=0;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

        x=i;

        cnt=0;

        while(x!=0){

        rem=x%10;

        cnt++;

        x=x/10;

            

            }

        if(cnt%2==1){

            flag++;

        }

    }

    printf("%d",flag);

    return 0; 

    }