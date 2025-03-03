// LNU_Algotesters

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

#include <fstream>

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



const int MAX = 100 * 10000 + 47;





int W[MAX];

bool U[MAX];

int X[MAX];



int main()

{

    

    //freopen("in.txt", "r", stdin);

    //ios::sync_with_stdio(false); cin.tie(0);

    

    int n;

    cin >> n;

    string S, T;

    cin >> S >> T;

    int idx = n - 1;

    FILL(W, -1);

    RFOR(i, n, 0)

    {

        while(idx >= 0 && (idx > i || S[idx] != T[i]))--idx;

        W[i] = idx;

        U[idx] = 1;

        X[idx] = max(X[idx], i);

    }

    

    if (S == T)

    {

        cout << 0 << endl;

        return 0;

    }

    

    FOR(i, 0, n)

        if (W[i] == -1)

        {

            cout << -1 << endl;

            return 0;

        }

    

    vector<PII> V;

    

    FOR(i, 0, n)

        if (U[i])V.PB(MP(i, X[i]));

    

    int ans = 0;

    

    FOR(i, 0, SZ(V))

    {

        int L = i, R = SZ(V);

        while(R - L > 1)

        {

            int M = (R + L) / 2;

            if (V[M].first + i >= V[i].second + M)

                R = M;

            else L = M;

        }

        ans = max(ans, R - i);

    }

    cout << ans << endl;

    

    

}






