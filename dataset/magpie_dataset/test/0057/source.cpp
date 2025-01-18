#include <iostream>

#include "stdc++.h"

using namespace std;



typedef vector<int> vi;

typedef bitset<20> MASK;

#define ll long long

#define PI 3.14159265359

//#define x first

#define y second

#define point pair<int,int>

#define clr(x, val)	memset((x), (val), sizeof(x))



//you don't know math, unless you can do math!

ll a[17][17];

ll cost[1 << 17];

vector<vector<ll>> masks;

ll n;

ll dp[1 << 17];

ll OO = 1e15;

ll solve(MASK mask){

    if(mask.count() == n)

        return 0;



    ll &ret = dp[mask.to_ulong()];

    if(ret != -1)

        return ret;



    ret = -OO;

    for(int i = 0; i < masks[mask.to_ulong()].size(); i++){

        ll c = cost[masks[mask.to_ulong()][i]];

        MASK new_mask = mask.to_ulong() | masks[mask.to_ulong()][i];



        ret = max(ret, solve(new_mask) + c);

    }



    return ret;

}



int main(){

    cin.tie(0);

    cin.sync_with_stdio(0);



    clr(dp, -1);

    cin>>n;

    masks = vector<vector<ll>> (1 << (n + 1));

    for(int i = 0; i < n; i++)

        for(int j = 0; j < n; j++)

            cin>>a[i][j];



    for(ll i = 0; i <= (1 << n); i++){

        MASK mask = i;

        ll ccost = 0;

        for(int k = 0; k < n; k++){

            if(!mask[k]) continue;

            for(int j = k + 1; j < n; j++){

                if(mask[j])

                    ccost+= a[k][j];

            }

        }



        cost[i] = ccost;

    }



    for(ll i = 0; i <= (1 << n); i++){

        MASK mask = i;

        mask.flip();

        int maskCopy = mask.to_ulong() & ((1 << n) - 1);



        for(int sub = maskCopy; sub > 0; sub = (sub - 1) & maskCopy){

            masks[i].push_back(sub);

        }

    }



    cout<<solve(0);

}
