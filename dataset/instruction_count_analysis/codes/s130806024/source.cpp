#include"stdc++.h"

using namespace std;

#define loop(i,L,R) for(int i=(L);i<=(R);i++)

#define rept(i,L,R) for(int i=(L);i<(R);i++)

#define isc(n) scanf("%d",&n)

#define llsc(n) scanf("%lld",&n)

#define dsc(n) scanf("%lf",&n)

#define enl cout<<endl

#define pb(x) push_back(x)

#define xx first

#define yy second

typedef long long ll;

typedef pair<int,int>PI;

typedef pair<pair<int,int>,int>PII;



map<int,int>a;

int main()

{

    int n,t;

    cin>>n;

    rept(i,0,n){cin>>t;a[t]++;}

    ll ans=0;

    for(auto i:a)

    {

        if(i.xx>i.yy)ans+=i.yy;

        else ans+=min((i.yy-i.xx),i.yy);

    }

    cout<<ans<<endl;

	return 0;

}


