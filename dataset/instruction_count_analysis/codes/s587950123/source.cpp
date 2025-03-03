#include "stdc++.h"



using namespace std;

#define sz(a) int(a.size())

#define ll  long long

#define ull unsigned long long

#define mod (ll)(1000000007)

#define endl '\n'

#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;

#define pi double(acos(-1))

#define S second

#define F first

#define mem(arr,a) memset(arr,a,sizeof arr)

//  freopen("input.txt","r",stdin);

// freopen("output.txt","w",stdout);

ll fp(ll n , ll p )

{

    if(p==0)

        return 1 ;

    if(p==1)

        return n%mod ;

    ll res ;

    res = fp(n,p/2)%mod;

    res = (res*res)%mod ;

    if(p%2)

        res = (res*n)%mod ;

    return res;

}





int main()

{

    ENGZ;

    pair<ll,ll> arr[200005] ;

    ll n , a = 0 , b;

    cin>>n ;

    for(int i=0 ; i <n ; i++)

    {

        cin>>arr[i].S >>arr[i].F ;

    }

    sort(arr,arr+n);

    bool f = 1 ;

    for(int i=0 ; i<n; i ++)

    {

        a+=arr[i].S ;

        if(a>arr[i].F)

            f=0 ;

    }

    if(f)cout<<"Yes"<<endl;

    else cout<<"No" <<endl ;

}
