#include<stdio.h>

int a[100005];

int main()

{

    int n;

    int flag=0;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

        scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)

    {

        if(a[i]==i)

        {

           int t=a[i+1];

           a[i+1]=a[i];

           a[i]=t;

           flag++;

        }

    }

    printf("%d\n",flag);

    return 0;

}