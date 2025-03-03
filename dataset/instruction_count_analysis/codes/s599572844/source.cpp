#include "stdc++.h"

#define hi ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define pb push_back

#define emb emplace_back

#define mp make_pair

#define srt(a) sort(a.begin(), a.end())

#define rsort(a) sort(a.rbegin(), a.rend())

#define reverse(a) reverse(a.begin(), a.end())

#define F first

#define S second

#define pii pair<int, int>

#define vi vector<int>

#define rep(i, a, b) for (int i = (a); i < (b); i++)

#define de(x) cout << #x << " is " << x << '\n'

typedef long long ll;

using namespace std;

int main()

{

    hi;

    int n, a;

    cin >> n;

    set<int> se;

    vector<int> res;

    rep(i, 0, n)

    {

        cin >> a;

        if (se.count(a))

        {

            se.erase(a);

            res.pb(a);

        }

        else

            se.insert(a);

    }

    rsort(res);

    if (res.size() >= 2)

    {

        cout << (ll)res[0] * (ll)res[1] << '\n';

    }

    else

        cout << 0;

    return 0;

}
