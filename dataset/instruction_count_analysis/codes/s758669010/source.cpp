#include "stdc++.h"

#define rep(i, a, n) for(int i = a; i < n; i++)

#define repr(i, a, b) for(int i = a; i >= b; i--)

#define int long long

#define all(a) a.begin(), a.end()

#define chmax(x, y) x = max(x, y)

#define chmin(x, y) x = min(x, y)

using namespace std;

typedef pair<int, int> P;

const int mod = 1000000007;

const int INF = 1e15;



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    int n;

    cin >> n;

    vector<string> s(n); 

    rep(i, 0, n) cin >> s[i];

    vector<string> t = s;   

    int ans = 0; 

    rep(i, 0, n){

        rep(j, 0, n){

            rep(k, 0, n){

                t[j][k] = s[(j + i) % n][k];

            }

        }

        bool g = true;

        rep(j, 0, n){

            rep(k, 0, n){

                if(t[j][k] != t[k][j]) g = false;

            }

        }

        if(g) ans += n;

    }

    cout << ans << endl;

}