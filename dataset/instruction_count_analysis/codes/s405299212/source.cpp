#include "stdc++.h"



using namespace std;

const int N=2e5+5,mod=1e9+7;

#define ll long long

ll a[N],b[N];

ll cum[N];

ll ans=0,R;

ll n,k;

bool valid(int r)

{

    ans=0;

    ll t=k;

    for(int i=0;i<n;i++)

    {

        ll idx=lower_bound(b,b+n,r-a[i])-b;

        if(idx==n) continue;

        idx=n-1-idx;

        if(idx<i) continue;

        ll sz=idx-i+1;

        t-=sz*2-1;

        ll sum=cum[idx];

        if(i) sum-=cum[i-1];

        ans+=sum*2+a[i]*(sz-1)*2;

    }

    R=t;

    return t>=0;

}

ll bs()

{

    ll s=0,e=2e5+5,mid;

    while(s<e)

    {

        mid=(s+e)/2;

        if(valid(mid)) e=mid;

        else s=mid+1;

    }

    return s;

}

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    cin>>n>>k;

    for(int i=0;i<n;i++)

        cin>>a[i],b[i]=a[i];

    sort(a,a+n);

    sort(b,b+n);

    reverse(a,a+n);

    cum[0]=a[0];

    for(int i=1;i<n;i++)

        cum[i]=cum[i-1]+a[i];



    ll B=bs();

    valid(B);

    cout<<ans+R*(B-1)<<endl;

    return 0;

}
