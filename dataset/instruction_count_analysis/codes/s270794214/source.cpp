#include"stdc++.h"

using namespace std;

#define reg register

#define ll long long

inline ll read()

{

	ll x=0,w=0;char ch=getchar();

	while(!isdigit(ch))w|=ch=='-',ch=getchar();

	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();

	return w?-x:x;

}

ll n,m,ans=1e15;

ll a[100005],b[100005];

int main()

{

    n=read(),m=read();reg int i;

    for(i=1;i<=n;++i)a[i]=read();

    for(i=2;i<=n;++i)

    {

        if(a[i]<a[i-1])

        {

            b[a[i-1]+2]--;b[1]+=a[i],b[2]-=a[i];b[2]--;b[a[i]+2]++;b[a[i]+1]+=m-a[i-1]+a[i];b[a[i]+2]-=m-a[i-1]+a[i];

        }

        else

        {

            b[1]+=a[i]-a[i-1],b[2]-=a[i]-a[i-1];b[a[i-1]+2]--;b[a[i]+2]++;b[a[i]+1]+=a[i]-a[i-1];b[a[i]+2]-=a[i]-a[i-1];

        }

    }

    for(i=1;i<=m;++i)b[i]+=b[i-1];for(i=1;i<=m;++i)b[i]+=b[i-1];

    for(i=1;i<=m;++i)ans=min(ans,b[i]);cout<<ans<<"\n";

	return 0;

}
