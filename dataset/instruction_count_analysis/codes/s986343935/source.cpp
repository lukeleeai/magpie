#include <iostream>

#include <algorithm>

#include <vector>

#include <map>

#include <set>

#include <string>

#include <cmath>

#include <iomanip>

#include <queue>

#include <unordered_map>

#include <unordered_set>

#include <bitset>

#include <cassert>

#include <cstring>

#include <climits>



using namespace std;



#define FOR(i, a, b) for (int i = (a); i < (b); i++)

#define REP(i, n) FOR(i, 0, n)

#define SORT(c) sort((c).begin(), (c).end())



typedef long long ll;

typedef pair<int, int> P;

typedef vector<int> V;

typedef map<int, int> M;



constexpr ll INF = 1e18;

constexpr ll MOD = 1e9 + 7;

constexpr double PI = 3.14159265358979323846;

constexpr int dx[] = {0, 0, 1, -1};

constexpr int dy[] = {1, -1, 0, 0};



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);



    int n, a[112345];

    int x = 0;



    cin >> n;

    REP(i, n)

    {

        cin >> a[i];

        x ^= a[i];

    }



    int res = 0;



    for (int i = 30; i >= 0; i--)

    {

        if (!(x & (1 << i)))

            continue;



        REP(j, n)

        {

            if ((a[j] ^ (a[j] - 1)) == (1 << (i + 1)) - 1)

            {

                res++;

                a[j] = 0;

                x ^= (1 << (i + 1)) - 1;



                break;

            }

        }

    }



    if (x == 0)

        cout << res << endl;

    else

        cout << -1 << endl;



    return 0;

}