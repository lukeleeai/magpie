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



    cin >> n;

    REP(i, n)

    cin >> a[i];



    int res = 0;



    bool used[112345] = {false};



    for (int i = 30; i >= 0; i--)

    {

        int cnt = 0;

        int exa = -1;

        REP(j, n)

        {

            if ((a[j] == (1 << i)) && !used[j])

                exa = j;

            if (a[j] & (1 << i))

            {

                cnt++;

                a[j] -= (1 << i);

            }

        }



        if (cnt % 2)

        {

            if (exa == -1)

            {

                cout << -1 << endl;

                return 0;

            }

            else

            {

                used[exa] = true;

                a[exa]--;

                a[exa] += (1 << i);

                res++;

            }

        }

    }



    cout << res << endl;



    return 0;

}