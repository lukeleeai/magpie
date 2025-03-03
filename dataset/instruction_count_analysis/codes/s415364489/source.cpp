#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<double,int> pdi;

const int N = 100005;

int a[N];

int fa[N];

vector<int> rec[N];

set<int> big[N];

map<int, int> mp;

int fat(int x)

{

    if(fa[x] == x)

        return x;

    return fa[x] = fat(fa[x]);

}

int main()

{



    int n, m, x, y, fax, fay;

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)

        fa[i] = i;

    for(int i = 1; i <= n; i++)

        scanf("%d", &a[i]);

    for(int i = 0; i < m; i++)

    {

        scanf("%d%d", &x, &y);

        fax = fat(x);

        fay = fat(y);

        if(fax != fay)

            fa[fax] = fay;

    }

    int cnt = 0;

    for(int i = 1; i <= n; i++)

    {

        int f = fat(i);

        if(!mp.count(f))

        {

            mp.insert(pii(f, ++cnt));

        }

        int id = mp[f];

        big[id].insert(a[i]);

    }

    int ans = 0;

    for(int i = 1; i <= n; i++)

    {

        int f = fat(i);

        int id = mp[f];

        if(big[id].count(i))

            ans++;

    }

    printf("%d\n", ans);

}














