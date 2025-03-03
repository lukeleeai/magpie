#include<stdio.h>



#define ll long long



int main()

{

    int n,k,s;

    scanf("%d%d%d",&n,&k,&s);

    for(int i=1;i<=k;++i)

    {

        printf("%d",s);

        if(i<k)putchar(32);

    }

    if(k<n)putchar(32);

    if(s==1)s=4;

    for(int i=k+1;i<=n;++i)

    {

        printf("%d",s-1);

        if(i<n)putchar(32);

    }

    return 0;

}