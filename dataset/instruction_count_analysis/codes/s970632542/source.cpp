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



const int MAX = 3 * 1000 * 100 + 47;

const double EPS = 1e-8;

const int MOD = 1000 * 1000 * 1000 + 7;





int A[4][4] =

{

    {1, 0, 0, 1},

    {1, 1, 0, 1},

    {1, 0, 1, 1},

    {1, 1, 1, 2}

};



int B[4][4] =

{

    {1, 0, 0, 0},

    {1, 1, 0, 0},

    {1, 0, 1, 0},

    {1, 1, 1, 1}

};



struct vect

{

    int A[4];

    vect()

    {

        FILL(A, 0);

    }

};



struct matrix

{

    int A[4][4];

    

    matrix()

    {

        FILL(A, 0);

    }

    

    matrix operator*(const matrix &m) const

    {

        matrix M;

        FOR(i, 0, 4)

            FOR(j, 0, 4)

                FOR(k, 0, 4)

                    M.A[i][j] = (M.A[i][j] + A[i][k] * 1LL* m.A[k][j]) % MOD;

        return M;

    }

    vect operator * (const vect& v) const

    {

        vect V;

        FOR(i, 0, 4)

            FOR(j, 0, 4)

                V.A[i] = (V.A[i] + A[i][j] * 1LL * v.A[j]) % MOD;

        return V;

    }

};





matrix BP(matrix M, int n)

{

    matrix RES;

    FOR(i, 0, 4)RES.A[i][i] = 1;

    while(n)

    {

        if (n & 1)RES = RES * M;

        M = M * M;

        n >>=1;

    }

    return RES;

}



int X[MAX];



int main()

{

    matrix A, B;

    FOR(i, 0, 4)FOR(j, 0, 4)A.A[i][j] = ::A[i][j];

    FOR(i, 0, 4)FOR(j, 0, 4)B.A[i][j] = ::B[i][j];

    

    int n, m;

    scanf("%d%d", &n, &m);

    FOR(i, 0, m)

    scanf("%d", X + i);

    X[m++] = n;

    

    vect V;

    V.A[0] = 1;

    FOR(i, 0, m)

    {

        matrix M = BP(A, X[i] - (i ? X[i-1] : 0) - 1);

        V = (M * B) * V;

    }

    cout << V.A[3] << endl;

    

    

    

}

    

    
