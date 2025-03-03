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

#include <complex>



using namespace std;



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



const int MAX = 2 * 1000 * 100 + 47;

const int MIN = 404;

const int MOD = INF;







struct RSQ

{

    int T[MAX << 2];

    int A[MAX];

    int n;

    

    void upd(int v, int tl, int tr, int pos)

    {

        if (tl == tr)

        {

            T[v] = !!A[tl];

            return ;

        }

        int tm = (tl + tr) / 2;

        if (pos <= tm)upd(v + v, tl, tm, pos);

        else upd(v + v + 1, tm+1, tr, pos);

        T[v] = T[v+v] + T[v+v+1];

    }

    void dec(int pos)

    {

        A[pos]--;

        upd(1, 0, n-1, pos);

    }

    

    void inc(int pos)

    {

        A[pos]++;

        upd(1, 0, n-1, pos);

    }

    

    

    int get()

    {

        return T[1];

    }

    

};



RSQ T;

int A[MAX];

int CNT[MAX];



int main()

{

    // freopen("in.txt", "r", stdin);

    int n, m;

    scanf("%d%d", &n, &m);

    T.n = n;

    FOR(i, 0, n)

    {

        scanf("%d", &A[i]);

        --A[i];

        CNT[A[i]]++;

    }

    

    FOR(i, 0, n)

        FOR(j, max(0, j - CNT[i] + 1), i+1)

            T.inc(j);

    

    FOR(q, 0, m)

    {

        int x, y;

        scanf("%d%d", &x, &y);

        --x, --y;

        int xx = A[x] - CNT[A[x]] + 1;

        if (xx >= 0)T.dec(xx);

        CNT[A[x]]--;

        A[x] = y;

        CNT[A[x]]++;

        xx = A[x] - CNT[A[x]] + 1;

        if (xx >= 0)T.inc(xx);

        

        printf("%d\n", n - T.get());

    }

    

    

    

    return 0;

}






