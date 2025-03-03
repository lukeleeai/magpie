#include "stdc++.h"

 

using namespace std;

 

typedef long long ll;

 

#define sz(x) (int)(x).size()

#define mp make_pair

#define pb push_back

#define f first

#define s second

#define lb lower_bound

#define ub upper_bound

#define all(x) x.begin(), x.end()

 

const int MOD = 1000000007;

const ll INF = 1e18;

const int MX = 100001;

 

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

 

    int n;

    cin >> n;

    vector <ll> a(n);

    for (int i=0;i<n;i++)

    cin >> a[i];

 

    ll ans[n];

    ans[0] = 0;

    for (int i=0;i<n;i++)

    {

        ans[0] += a[i];

        if (i % 2 == 1)

        ans[0] -= 2*a[i];

    }

 

    ans[0] = ans[0] / 2;

    for (int i=1;i<n;i++) {

        ans[i] = a[i-1] - ans[i-1];

    }

 

    for (int i=0;i<n;i++) {

        cout << ans[i] * 2 << " ";

    }

 



}