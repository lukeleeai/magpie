#include "stdc++.h"

#define f first

#define s second

#define mp make_pair

#define pb push_back



using namespace std;



typedef long long ll;

typedef pair<int,int> ii;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<ll> vll;



int n;

vll dp(1000005, -1);

vector<bool> broken(1000005, false);



ll f(int p) {

    if (broken[p]) {

        return 0;

    }

    if (p == n || p == n-1) {

        return 1;

    }

    if (dp[p] != -1) {

        return dp[p];

    }

    ll ans = (f(p+1) + f(p+2)) % ((ll)(1e9 + 7));

    dp[p] = ans;

    return ans;

}



int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);

	

    int m, val;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {

        cin >> val;

        broken[val] = true;

    }

	

    cout << f(0) << endl;

	

	return 0;

}
