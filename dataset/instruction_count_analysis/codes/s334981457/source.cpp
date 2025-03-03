#include "stdc++.h"

using namespace std;



typedef long long ll;

ll memo[1000002];

ll n;

map<ll,bool> s;



ll dp(ll x){

    if (x>n)

    {

        memo[x] = 0;

        return 0;

    }



    if (s[x]){

        memo[x] = 0;

        return 0;

    }

    ll to_add = 0;

    if (x==n)

    {

        return 1;

    }

    if (memo[x] != -1)

        return memo[x];

    else

    {

        if(!s[x+1])

        to_add += dp(x+1);

        if (!s[x+2]&&x+2<=n)

            to_add += dp(x+2);

        memo[x] = to_add%1000000007;

        return memo[x];

    }



}



int main()

{

    memset(memo, -1, sizeof(memo));

    // memo[n] = 1;

    ll m, t;

    cin>>n>>m;

    while(m--)

    {

        cin>>t;

        s[t]=1;

    }

    cout<<dp(0)<<'\n';



    return 0;



}