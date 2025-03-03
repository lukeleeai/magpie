#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<math.h>

using namespace std;

#define N 100010

int l[N],r[N];



int main()

{

    int n,i,j,k,x,t1,t2,s1,s2;

    long long ans;

    scanf("%d",&n);

    for(i=0;i<n;i++)

        scanf("%d%d",&l[i],&r[i]);

    sort(l,l+n+1);

    sort(r,r+n+1);

    ans=0;

    for(i=0;i<n;i++)

    {

        if(l[n-i]<=r[i])

            break;

        ans=ans+l[n-i]-r[i];

    }

    printf("%lld\n",ans*2);

    return 0;

}
