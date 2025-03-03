#include "stdc++.h"

using namespace std;



typedef long long int ll;

typedef pair<ll, ll> pll;



#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))

#define REP(i, n) FOR(i, n, 0)

#define OF64 std::setprecision(10)



const ll MOD = 1000000007;

const ll INF = (ll)1e15;



ll N;

string S;

ll T[100005];

bool check(ll k)

{

    REP(n, 2)

    {

        memset(T, 0, sizeof(T));

        ll m = 0;

        string s = "";

        REP(i, N)

        {

            m += T[i];

            ll t = (S[i] - '0' + m) % 2;



            if (i + k <= N && t != n)

            {

                m++;

                T[i + k] = -1;

                t = (t + 1) % 2;

            }

            s.push_back(t + '0');

        }



        ll max = 0;

        ll sum = 0;

        REP(i, N)

        {

            sum++;

            if (i == N - 1 || s[i] != s[i + 1])

            {

                max = std::max(max, sum);

                sum = 0;

            }

        }



        if (max >= k)

            return true;

    }

    return false;

}



int main()

{

    cin >> S;

    N = S.length();

    ll ok = 1, ng = N + 1;

    while (abs(ok - ng) > 1)

    {

        ll mid = (ok + ng) / 2;

        if (check(mid))

            ok = mid;

        else

            ng = mid;

    }

    cout << ok << endl;



    return 0;

}