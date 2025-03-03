#include "stdc++.h"

using namespace std;

#define int long long

const int maxn=1e5+10;

int a[maxn];

int cmp(const int a,const int b){return a>b;}

int n,m,v,p,b[maxn];

bool check(int mid)

{

    if(mid<=p)return 1;

    if(a[mid]+m<a[p])return 0;

    if(v<=p-1&&a[mid]+m>=a[p])return 1;

    for(int i=1;i<=n;i++)b[i]=a[i];

    int temp=0;

    for(int i=1;i<=p-1;i++)b[i]+=m,temp+=m;

    int inx=n,cnt=v-p+1;

    while(inx>mid&&cnt>1)temp+=m,inx--,cnt--,b[inx]+=m;

    temp+=m;

    int now=a[mid]+m;

    int res=m*v-temp;

    for(int i=p;i<mid;i++)

	{

        int add=min(m,max(now-a[i],0ll));

        if(add>res)add=res;

        res-=add,b[i]+=add;

    }

    return now>=b[p]&&res<=0;

}

signed main()

{

    cin>>n>>m>>v>>p;

    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1,cmp);

    int l=1,r=n;

    int ans=0;

    while(l<=r)

	{

        int mid=(l+r)>>1;

        if(check(mid))l=mid+1,ans=mid;

        else r=mid-1;

    }

    cout<<ans<<endl;

    return 0;

}