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

ll a[1005];

int main()

{

    //IOS;

    while(cin>>n)

    {

        map<ll,ll> m;

        vector<ll> ans;

        rep(i,n)

        {

            ll tmp;

            cin>>tmp;

            m[tmp]++;

            if(m[tmp]%2==0) ans.pb(tmp);

        }

        sort(ans.begin(),ans.end());

        if(ans.size()<2) cout<<0<<"\n";

        else cout<<ans[ans.size()-1]*ans[ans.size()-2]<<"\n";

    }

    return 0;

}


