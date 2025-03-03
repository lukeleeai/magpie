#include "stdc++.h"

#define INF 1e18

#define int long long

#define Rep(i, a, n) for (int i = (a); i < (n); i++)

#define rep(i, n) Rep(i, 0, n)

#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> P;

typedef pair<int, P> PP;

const int mod = 1000000007;



#define N 200010

int par[N], Rank[N], SIZE[N];



void init(int n)

{

    rep(i, n)

    {

        par[i] = i;

        Rank[i] = 0;

        SIZE[i] = 1;

    }

}

int find(int x)

{

    if (par[x] == x)

        return x;

    else

        return par[x] = find(par[x]);

}

void unit(int x, int y)

{

    x = find(x);

    y = find(y);

    if (x == y)

        return;



    if (Rank[x] < Rank[y])

    {

        par[x] = y;

        SIZE[y] += SIZE[x];

    }

    else

    {

        par[y] = x;

        SIZE[x] += SIZE[y];

        if (Rank[x] == Rank[y])

            Rank[x]++;

    }

}

bool same(int x, int y)

{

    return find(x) == find(y);

}



signed main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);



    int n, m;

    cin >> n >> m;

    init(n + m);

    rep(i, n)

    {

        int k;

        cin >> k;

        rep(j, k)

        {

            int l;

            cin >> l;

            l += (n - 1);

            unit(i, l);

        }

    }

    rep(i, n) if (!same(0, i))

    {

        cout << "NO" << endl;

        return 0;

    }

    cout << "YES" << endl;

}