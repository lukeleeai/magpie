#include"stdc++.h"

using namespace std;

#define pb push_back

#define rep(i,n) for(int i=0;i<n;i++)

#define rep1(i,n) for(int i=1;i<=n;i++)

#define mp make_pair

#define F first

#define S second

#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

vector<int> g[100005];

ll q,n;

ll a[1500005];

int main()

{

    //IOS;

    ll x,y;

    while(cin>>x>>y)

    {

        ll sum=0;

        for(sum=0;x<=y;x=x*2,sum++);

        cout<<sum<<"\n";

    }

    return 0;

}


