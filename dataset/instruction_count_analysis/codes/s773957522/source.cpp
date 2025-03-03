#pragma GCC optimize("Ofast")

#include <cstdio>

#include <cstdlib>

#include <string>

#include <algorithm>

#include <iostream>

#include <queue>

#include <vector>

#include <bitset>

#include <cmath>

#include <limits>

#include <iostream>

#include <map>

#include <set>

#include <tuple>

using namespace std;

#define INF 1LL << 30

#define MAX 100000

#define MOD 1000000007

typedef long long ll;

typedef pair<int,int> P;

//typedef pair<pair<int,int>,int> p;

#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/

#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

struct edge

{

    ll to, cost, val;

};

template <class T, class U>

bool chmin(T &a, const U &b)

{

    if (a <= b)

        return false;

    a = b;

    return true;

}

template <class T, class U>

bool chmax(T &a, const U &b)

{

    if (a >= b)

        return false;

    a = b;

    return true;

}

//__builtin_popcount(S);

//C.erase(unique(C.begin(),C.end()),C.end());

//#define int ll



int C[210000];

ll dp[210000],pre[210000];



signed main(void)

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int N;

    cin>>N;

    vector<int> V;

    for(int i=0;i<N;i++) cin>>C[i];

    int now=C[0];

    V.push_back(-1);

    V.push_back(now);

    for(int i=1;i<N;i++){

        while(now==C[i]){

            i++;

        }

        if(i>=N) break;

        now=C[i];

        V.push_back(now);

    }

    N=(int)V.size();

    dp[0]=1;

    for(int i=1;i<=N;i++){

        dp[i]=dp[i-1]+pre[V[i]];

        dp[i]%=MOD;

        pre[V[i]]=dp[i];

    }

    cout<<dp[N]<<endl;

}
