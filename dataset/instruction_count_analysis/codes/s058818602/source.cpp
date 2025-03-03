#include "stdc++.h"

using namespace std;



int n;

int par[100010];

int Rank[100010];



void init(int n)

{

    for (int i = 0; i < n; i++)

    {

        par[i] = i;

        Rank[i] = 0;

    }

}

int find(int x)

{

    if (par[x] == x)

    {

        return x;

    }

    else

    {

        return par[x] = find(par[x]);

    }

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

    }

    else

    {

        par[y] = x;

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



    int m;

    cin >> n >> m;

    vector<int> cnt[100010];

    for (int i = 0; i < n; i++)

    {

        int k;

        cin >> k;

        for (int j = 0; j < k; j++)

        {

            int a;

            cin >> a;

            a--;

            cnt[a].push_back(i);

        }

    }

    init(n);

    for (int i = 0; i < m; i++)

    {

        for (int j = 0; j < cnt[i].size(); j++)

        {

            unit(cnt[i][0], cnt[i][j]);

        }

    }

    bool f = true;

    for (int i = 0; i < n; i++)

    {

        f = f && same(0, i);

    }

    if (f)

        cout << "YES" << endl;

    else

        cout << "NO" << endl;

}