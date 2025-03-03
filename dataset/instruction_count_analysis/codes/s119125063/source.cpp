#include<stdio.h>

int main()

{

    long long int N,A,B,a[100005],i,sum=0;

    scanf("%lld%lld%lld",&N,&A,&B);

    for(i=0;i<N;i++)

        scanf("%lld",&a[i]);

    for(i=0;i<N-1;i++)

       {

        if((a[i+1]-a[i])*A<B)

        sum+=(a[i+1]-a[i])*A;

        else

            sum+=B;

       }

       printf("%lld",sum);

}
