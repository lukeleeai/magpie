#include<stdio.h>

int t[100010],x[100010],y[100010];

int main()

{

    int n,sum=0;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

        scanf("%d%d%d",&t[i],&x[i],&y[i]);

    for(int i=1;i<=n;i++)

    {

        sum=x[i]+y[i]-x[i-1]-y[i-1];

        if((t[i]-t[i-1])<sum)

        {

            printf("No\n");

            return 0;

        }

        if((sum-(t[i]-t[i-1]))%2)

        {

            printf("No\n");

            return 0;

        }

    }

    printf("Yes\n");

    return 0;

}
