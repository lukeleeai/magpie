#include<stdio.h>

int main()

{

    int N,M,A[10007],i,sum=0,r;

    scanf("%d%d",&N,&M);

    for(i=0;i<M;i++)

    {

        scanf("%d",&A[i]);

        sum=sum+A[i];





    }

    if(N>=sum)

    {

        r=N-sum;

    }

    else r=-1;

    printf("%d",r);





}


