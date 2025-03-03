

#include <stdio.h>

#include <stdlib.h>

 

 

int main()

{

    int n,i,x;

    scanf("%d %d",&n,&x);

    long long ans=0,sum,a,b;

    scanf("%lld",&a); //第一个 盒子中的糖果个数

    if(a>x)   // x 是最后每个盒子要剩余的个数，  如果第一个盒子的糖果个数a大于x

    {

       ans+=a-x;  //  ans 是多出的个数

       a=x; 

    }

 

    for( i=1; i<n; i++) //剩下的 n-1 个盒子

    {

        scanf("%lld",&b);  

        sum=a+b;

        if(sum>x)

        {

            ans+=sum-x;

            a=b-sum+x;   

        }

        else a=b;       

    }                   

    printf("%lld",ans); // 

    return 0;

}