#include "stdc++.h"

const int maxn=1e5+5;

const int mod=1e9+7;

#define ll long long

using namespace std;

ll a[maxn],b[maxn];

ll aa[maxn],bb[maxn];

int main()

{

    int i,j,n,m;

    ll h=0,w=0;

    scanf("%d%d",&n,&m);

    for(i=1; i<=n; i++)

    {

        scanf("%lld",&a[i]);

    }

    for(i=1; i<=m; i++)

    {

        scanf("%lld",&b[i]);

    }

//    for(i=1; i<=n; i++)

//    {

//        scanf("%d",&a[i]);

//        aa[i]=aa[i-1]+a[i];

//    }

//    for(i=1; i<=m; i++)

//    {

//        scanf("%d",&b[i]);

//        bb[i]=bb[i-1]+b[i];

//    }

//    for(i=1; i<n; i++)

//    {

//        h+=aa[n]-aa[i]-(a[i]%mod*(n-i)%mod)%mod;

//        if(h>=mod) h-=mod;

//    }

//    cout<<h<<endl;

//    for(i=1; i<m; i++)

//    {

//        w+=bb[m]-bb[i]-b[i]*(m-i);

//        if(w>=mod) w-=mod;

//    }

//    cout<<w<<endl;

    for(int l=1, r=n; l<r; ++l,--r)

        w = (w + (a[r]-a[l])*(r-l))%mod;

    for(int l=1, r=m; l<r; ++l,--r)

        h = (h + (b[r]-b[l])*(r-l))%mod;

    cout<<(w*h)%mod<<endl;

    return 0;

}

/*622259192

993828220*/
