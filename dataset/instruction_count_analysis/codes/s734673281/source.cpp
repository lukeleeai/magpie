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



const int MAX = 111;

const double EPS = 1e-8;

const int MOD = 1000 * 1000 * 1000 + 7;





int A[MAX];

int DP[MAX][MAX][MAX];





int main()

{

    int n;

    scanf("%d", &n);

    int N = n + n - 1;

    FOR (i, 0, N)

        scanf("%d", &A[i]);

    sort(A, A + N);

    

    DP[0][1][0] = 1;

    FOR(i, 0, n)

    {

        FOR(j, 0, N + 1)

        {

            FOR(k, 0, j)

            {

                if (DP[i][j][k] == 0)continue;

                

                int l = n - i - 1;

                int r = n + i;

                

                int jj = j + (l > 0 && A[l] != A[l-1]) + (r < N && A[r] != A[r-1]);

                int kk = k + (l > 0 && A[l] != A[l-1]);

                

                FOR(x, 0, jj)

                {

                    int jjj = jj - max(0, abs(x - kk) - 1);

                    int kkk = min(x, kk + 1);

                    

                    DP[i+1][jjj][kkk] += DP[i][j][k];

                    if (DP[i+1][jjj][kkk] >= MOD)

                        DP[i+1][jjj][kkk] -= MOD;

                }

                

                

                

            }

        }

    }

    int res = 0;

    FOR(i, 0, N + 1)

        FOR(j, 0, i)

    {

        res += DP[n-1][i][j];

        if (res >= MOD)res -= MOD;

    }

    

    cout << res << endl;

    

    

}

    

    
