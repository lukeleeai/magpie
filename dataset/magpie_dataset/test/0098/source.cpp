// Math = ♥️



#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;



/*-------------------------------------------------------------------------------------------------------------------------*/

#define ll long long                  // Short form for long long

#define ld long double                // Short form for long double

typedef pair<ll, ll> ii;              // Pair of long long

typedef vector<ll> vi;                // Vector of long long

typedef vector<vi> vvi;               // Vector of vector of long long

typedef vector<ii> vii;               // Vector of pairs

typedef vector<vii> vvii;             // Vector of vector of pairs

#define pq priority_queue             // Max heap (To convert to min heap, use negative sign before every value)

#define ff first                      // For pairs

#define ss second                     // For pairs

#define pb push_back                  // Pushback to vector

#define mp make_pair                  // Makes pairs to be stored as pair

#define all(c) (c).begin(), (c).end() // Mainly used by me in sorting

// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()

// order_of_key returns number of elements less that parameter. If element exists, that order is its index

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

/*-------------------------------------------------------------------------------------------------------------------------*/



vi arr;

vii dp;

ll n;



ii solve(ll bit)

{

    if (dp[bit] == mp(-1ll, -1ll))

    {

        ii maxi = {bit, 0};

        if (arr[0] > arr[bit])

            swap(maxi.ff, maxi.ss);

        for (int i = n; i >= 0; i--)

        {

            ll check = (1 << i);

            if (bit & check)

            {

                auto c = solve(bit & (~(check)));

                if (c.ff != maxi.ff && c.ff != maxi.ss)

                {

                    if (arr[c.ff] > arr[maxi.ff])

                        maxi.ss = maxi.ff, maxi.ff = c.ff;

                    else if (arr[c.ff] > arr[maxi.ss])

                        maxi.ss = c.ff;

                }



                if (c.ss != maxi.ff && c.ss != maxi.ss)

                {

                    if (arr[c.ss] > arr[maxi.ff])

                        maxi.ss = maxi.ff, maxi.ff = c.ss;

                    else if (arr[c.ss] > arr[maxi.ss])

                        maxi.ss = c.ss;

                }

            }

        }

        dp[bit] = maxi;

    }

    return dp[bit];

}



int main(void)

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    cin >> n;



    ll N = (1 << n);

    arr.resize(N);



    for (int i = 0; i < N; i++)

        cin >> arr[i];



    dp.resize(N, {-1, -1});

    dp[0] = {0, 0};

    solve(N - 1);



    ll prev = 0;

    for (int i = 1; i < N; i++)

    {

        prev = max(prev, arr[dp[i].ff] + arr[dp[i].ss]);

        cout << prev << "\n";

    }

}
