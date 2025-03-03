#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<algorithm>

using namespace std;



typedef long long LL;



const int N=100005;



int n,m;

LL stack[N],t[N],ans[N],a[N];



int binary(int r,LL k)

{

    int l=1;

    while (l<=r)

    {

        int mid=(l+r)/2;

        if (a[mid]<=k) l=mid+1;

        else r=mid-1;

    }

    return l-1;

}



int main()

{

    scanf("%d%d",&n,&m);

    int top=0;

    stack[++top]=n;

    for (int i=1;i<=m;i++)

    {

        LL x;cin>>x;

        while (x<=stack[top]) top--;

        stack[++top]=x;

    }

    m=top;

    for (int i=1;i<=top;i++) a[i]=stack[i];

    t[m]=1;

    for (int i=m;i>=1;i--)

    {

        LL k=a[i];int p=binary(i-1,k);

        while (p)

        {

            t[p]+=k/a[p]*t[i];

            k%=a[p];

            p=binary(p-1,k);

        }

        ans[k]+=t[i];

    }

    for (int i=n;i>=1;i--) ans[i]+=ans[i+1];

    for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);

    return 0;

}