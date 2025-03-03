#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<math.h>

#include<vector>

using namespace std;

#define N 100010

#define LL long long

int a[N];

vector<LL> q;

int main()

{

    int i,j,k,n,m;

    int x,y,z;

    LL d,t,s;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)

        scanf("%d",&a[i]);

    for(i=1;i<=n;i++)

    {

        d=0;

        for(j=i;j<=n;j++)

        {

            d=d+a[j];

            q.push_back(d);

        }

    }

    s=0;

    for(i=40;i>=0;i--)

    {

        d=s|(LL)pow(2,i);

        k=0;

        for(j=0;j<n*(n+1)/2;j++)

        if((q[j]&d)==d)

            k++;

        if(k>=m)

            s=s+(LL)pow(2,i);

    }

    printf("%lld\n",s);

    return 0;

}
