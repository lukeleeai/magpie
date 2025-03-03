#include<stdio.h>

#include<algorithm>

using namespace std;

int main()

{

    int n;

    scanf("%d",&n);

    int a[n];

    int num=0;

    for(int i=0; i<n; i++)

    {

        scanf("%d",&a[i]);

    }

    sort(a,a+n);

    for(int i=0; i<n; i++)

    {

        if(a[i]==a[i+1])

        {

            a[i]=a[i+1]=0;

        }

    }

    for(int i=0; i<n; i++)

    {

        if(a[i]!=0)

        {

            num++;

        }

    }

    printf("%d\n",num);

    return 0;

}