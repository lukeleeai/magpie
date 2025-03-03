#include <iostream>

#include <sstream>

#include <iomanip>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <cctype>

#include <cstring>

#include <vector>

#include <list>

#include <queue>

#include <deque>

#include <stack>

#include <map>

#include <set>

#include <algorithm>

#include <iterator>

#include <bitset>

#include <ctime>

using namespace std;



#define F(i, n) for(int i = 0; i < n; ++i)

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)

#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define FILL(a,value) memset(a, value, sizeof(a))



#define SZ(a) (int)a.size()

#define ALL(a) a.begin(), a.end()

#define PB push_back

#define MP make_pair



typedef long long LL;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const int INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL) INF;



const int MAX = 200*1000+47;



VI G[MAX];

int A[MAX];



bool ok;





LL DFS(int v, int p)

{

    LL val = A[v];

    bool leaf = (SZ(G[v]) == 1);

    if (!leaf)val *= 2;

    LL ans = val;

    FOR(i, 0, SZ(G[v]))

    {

        int to = G[v][i];

        if (to == p)continue;

        LL res = DFS(to, v);

        if (!leaf && res * 2 > val)ok = false;

        ans -= res;

    }

    

    if (!leaf && ans * 2 > val)ok = false;

    if (ans < 0)ok = false;

    return ans;

}



int main()

{

    int n;

    scanf("%d", &n);

    FOR(i, 0, n)scanf("%d", A + i);

    

    FOR(i, 0, n-1)

    {

        int a, b;

        scanf("%d%d", &a, &b);

        --a, --b;

        G[a].PB(b);

        G[b].PB(a);

    }

    ok = true;

    if (DFS(0, -1) == 0 && ok)

    {

        printf("YES\n");

    }

    else

    {

        printf("NO\n");

    }

    

    return 0;

}


















