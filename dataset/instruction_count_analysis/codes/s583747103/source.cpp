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



typedef unsigned long long LL;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const int INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL) INF;



const double EPS = 1e-6;

const int MAX = 2000 * 100 + 47;





PII A[MAX];

PII B[MAX];

int DP[MAX];



int main()

{

    int x, y, xx, yy;

    scanf("%d%d%d%d", &x, &y, &xx, &yy);

    int n;

    scanf("%d", &n);

    FOR(i, 0, n)

        scanf("%d%d", &A[i].first, &A[i].second);

    

    if (x > xx)swap(x, xx), swap(y, yy);

    if (y > yy)

    {

        FOR(i, 0, n) A[i].second *= -1;

        y *= -1, yy *= -1;

    }

    int sz = 0;

    FOR(i, 0, n)

    {

        if (A[i].first < x || A[i].first > xx)continue;

        if (A[i].second < y || A[i].second > yy)continue;

        B[sz++] = A[i];

    }

    sort(B, B + sz);

    FOR(i, 0, MAX)

        DP[i] = INF;

    int mx = 0;

    FOR(i, 0, sz)

    {

        int j = lower_bound(DP, DP + n, B[i].second) - DP;

        DP[j] = B[i].second;

        mx = max(mx, j+1);

    }

    double ans = (xx - x) + (yy - y);

    ans *= 100;

    if (mx == xx - x + 1 || mx == yy - y + 1)ans += 5 * PI;

    ans += mx * (5 * PI - 20);

    printf("%.11f\n", ans);

}
