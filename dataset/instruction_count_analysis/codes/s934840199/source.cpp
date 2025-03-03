#include "stdc++.h"

using namespace std;

#define mod 1000000007

#define N 100005

#define ll long long

#define ull unsigned long long

#define loop1(i, j, k, step) for (int i = j; i < k; i += step)

#define loop(i, j, k) for (int i = j; i < k; i++)

#define rloop1(i, j, k, step) for (int i = j; i >= k; i -= step)

#define rloop(i, j, k) for (int i = j; i >= k; i--)

#define rep(i, k) for (int i = (0); i < (k); i++)

#define rrep(i, k) for (int i = k - 1; i >= 0; i--)



#define forall(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define mp make_pair

#define pb push_back

#define pop pop_back

#define F first

#define S second

#define sz(x) (int)(x).size()

#define endl "\n"

#define Max (int)INT_MAX

#define Min (int)INT_MIN

#define MEM(a, b) memset(a, (b), sizeof(a))

#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL)

#define lin puts("");

typedef vector<int> vi;

typedef pair<int, int> pi;

typedef vector<ll> vl;

typedef pair<ll, ll> pll;

//char ch[101][101];

char c;

int arr[10000], brr[105];



void solve()

{

    string s;

    cin >> s;

    if (s.size() < 6 || s.size() > 6)

    {

        cout << "No" << endl;

        return;

    }

    if (s[2] == s[3] && s[4] == s[5])

    {

        cout << "Yes" << endl;

    }

    else

    {

        cout << "No" << endl;

    }

}

int main()

{

    auto start = clock();

    fast_io;

    //freopen("test.txt", "r", stdin);

    int t;

    t = 1;

    // cin >> t;

    while (t--)

    {

        solve();

    }

    auto stop = clock();

    cerr << "time taken:" << double(stop - start) / double(CLOCKS_PER_SEC) << " s" << endl;

    return 0;

}