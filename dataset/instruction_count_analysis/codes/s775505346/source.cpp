#include "stdc++.h"

using namespace std;



typedef long long int ll;

typedef pair<ll, ll> pll;



#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))

#define REP(i, n) FOR(i, n, 0)

#define OF64 std::setprecision(10)



const ll MOD = 1000000007;

const ll INF = (ll)1e15;



bool L[200005];



int main()

{

    ll N;

    string S;

    cin >> N >> S;

    memset(L, 0, sizeof(L));

    ll l = 0;

    REP(i, 2 * N)

    {

        if (l % 2 == 0 && S[i] == 'B')

        {

            L[i] = true;

            l++;

        }

        else if (l % 2 == 1 && S[i] == 'W')

        {

            L[i] = true;

            l++;

        }

        else

            l--;

    }

    if (l != 0)

    {

        cout << 0 << endl;

        return 0;

    }



    ll ans = 1;

    ll r = 0;

    REP(i, 2 * N)

    {

        if (!L[2 * N - 1 - i])

            r++;

        else

            ans = (ans * r--) % MOD;

    }

    REP(i, N)

    {

        ans = (ans * (i + 1)) % MOD;

    }

    cout << ans << endl;

    return 0;

}