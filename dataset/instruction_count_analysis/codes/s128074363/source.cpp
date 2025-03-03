#include "stdc++.h"

using namespace std;



typedef long long int ll;

typedef pair<ll, ll> pll;



#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))

#define REP(i, n) FOR(i, n, 0)

#define OF64 std::setprecision(10)



const ll MOD = 1000000007;

const ll INF = (ll)1e15;



string S[305];

ll A[305][305];

ll T[305];

int main()

{

    ll H, W, K;

    cin >> H >> W >> K;

    REP(i, H)

    {

        cin >> S[i];

    }



    memset(A, 0, sizeof(A));

    memset(T, 0, sizeof(T));

    REP(i, W)

    {

        REP(j, H)

        {

            if (S[j][i] == '#')

                T[i]++;

        }

    }



    int index = 1;

    ll prev = 0;

    for (ll w = 0; w < W; ++w)

    {

        if (T[w] == 0)

            continue;



        for (ll h = 0; h < H; ++h)

        {

            ll p = T[w];

            for (ll k = prev; k <= w; ++k)

            {

                A[h][k] = index;

                if (S[h][k] == '#')

                    T[w]--;

            }



            if (p != T[w] && T[w] > 0)

                index++;

        }

        index++;

        prev = w + 1;

    }

    REP(i, H)

    {

        REP(j, W)

        {

            if (A[i][j] == 0 && j > 0)

                A[i][j] = A[i][j - 1];

        }

    }



    REP(i, H)

    {

        REP(j, W)

        {

            cout << A[i][j];

            if (j < W - 1)

                cout << " ";

        }

        cout << endl;

    }

    return 0;

}