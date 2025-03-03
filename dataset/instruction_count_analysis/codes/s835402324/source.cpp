#include"stdc++.h"

using namespace std;

typedef long long ll;

#define MM 1000000000

#define MOD MM+7

#define MAX 101000

#define MAP 110

#define initial_value -1

#define Pair pair<int,int>

#define lPair pair<ll,ll>

#define chmax(a,b) (a<b ? a=b:0)

#define chmin(a,b) (a>b ? a=b:0)

int dx[4] = {-1,0,1,0};

int dy[4] = {0,-1,0,1};



vector<int> places[200200];

ll dp[200200];

void add(ll &a, ll b) { a+=b; if(a >= MOD) a -= MOD;}

int main(){

    int N; cin >> N;

    map<char,int> mp;

    string s; cin >> s;

    for(int i = 0; i < N; i++){

        mp[s[i]]++;

    }

    ll ans = 1;

    for(char t = 'a'; t <= 'z'; t++){

        if(mp[t] == 0) continue;

        ans *= (mp[t]+1);

        ans %= MOD;

    }

    cout << ans-1 << endl;

}