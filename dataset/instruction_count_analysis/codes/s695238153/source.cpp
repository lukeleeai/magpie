#include<stdio.h>

int n,r,l,a;

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

	scanf("%d%d",&l,&r);

    a+=r-l+1;

	}

    printf("%d\n",a);

    return 0;

}