#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long long int llint;

#define MM 1000000000

#define MOD MM+7

#define MAX 101000

#define MAP 110

#define initial_value -1

#define Pair pair<int,int>

#define chmax(a,b) (a<b ? a=b:0)

#define chmin(a,b) (a>b ? a=b:0)

#define INF (1 << 29) //536870912

int dx[4] = {-1,0,1,0};

int dy[4] = {0,-1,0,1};

int main(){

    int n; cin >> n;

    string s; cin >> s;

    map<char,int> mp;

    for(int i = 0; i < n; i++){

        mp[s[i]]++;

    }

    ll ans = 1;

    for(char t = 'a'; t <= 'z'; t++){

        if(mp[t] == 0) continue;

        ans *= (mp[t] + 1);

        ans %= MOD;

    }

    cout << ans-1 << endl;

}



 