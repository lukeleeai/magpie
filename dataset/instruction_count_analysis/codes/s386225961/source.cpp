#include<stdio.h>

#include<string.h>

#include<algorithm>

#define ll long long

using namespace std;

int main()

{

    int n;

    scanf("%d",&n);

    ll a[n];

    for(int i=0; i<n; i++)

        scanf("%lld",&a[i]);

    sort(a,a+n);

    ll c,k;

    int f=1;

    for(int i=n-1; i>=0; i--)

    {

        if(a[i]==a[i-1]&&f==1)

        {

            c=a[i];

            f=3;

            i-=2;

        }

        if(a[i]==a[i-1]&&f==3)

        {

            k=a[i];

            break;

        }

    }

    if(f==3)

        printf("%lld\n",c*k);

    else

        printf("0\n");

    return 0;

}
