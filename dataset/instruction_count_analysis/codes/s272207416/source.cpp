#include<stdio.h>

#include<algorithm>

using namespace std;

int a[100005];

int main()

{

    int n,flag=0;

    long long p,q;

    scanf("%d",&n);

    for(int i=0;i<n;i++)

        scanf("%d",&a[i]);

    sort(a,a+n);

    for(int i=n-1;i>0;)

    {

        if(a[i]==a[i-1]&&flag==0)

        {

            p=a[i];

            flag=1;

            i=i-2;

        }

        else if(a[i]==a[i-1]&&flag==1)

        {

            q=a[i];

            flag=2;

            break;

        }

        else if(a[i]!=a[i-1])

            i--;

    }

    if(flag!=2)

        printf("0\n");

    else

        printf("%lld\n",p*q);

    return 0;

}