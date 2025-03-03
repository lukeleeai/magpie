#include "stdc++.h"



using namespace std;



#define REP(i,a,b) for(ll i = a; i < b; i++)

#define DB( x ) cout << #x << " = " << x << endl;

#define sz(s) ((int)((s).size()))

#define endl '\n'



typedef long long ll;

typedef unsigned long long ull;

typedef pair<ll, ll> pii;

typedef pair<int, pii> tri;

typedef vector <vector <ll>> matrix;

typedef pair<string, string> pss;



const ll mod = (ll)1e9 + 7;

const int MAX = (int)1e3 + 100;



const int oo = 0x3f3f3f3f;



char mat[MAX][MAX];



int n, m;



ll dp[MAX][MAX];



ll Solve(int i, int j){

    if(i > n || j > m)

        return 0;

    if(i == n && j == m)

        return 1LL;



    if(dp[i][j] != -1)

        return dp[i][j];



    ll ans = 0;



    int x = i + 1, y = j;



    if(mat[x][y] == '.')

        ans = (ans + Solve(x, y)) % mod;



    x = i, y = j + 1;



    if(mat[x][y] == '.')

        ans = (ans + Solve(x, y)) % mod;



    return dp[i][j] = ans;

}



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    cin >> n >> m;



    for(int i = 1;i <= n;++i){

        string s; cin >> s;

        for(int j = 1;j <= m;++j)

            mat[i][j] = s[j - 1];

    }



    memset(dp, -1, sizeof(dp));



    cout << Solve(1, 1) << endl;

}
