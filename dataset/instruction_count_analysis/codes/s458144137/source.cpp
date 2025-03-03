#include <iostream>

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

#include <bitset>

#include <algorithm>

#include <cstdio>

#include <time.h>

#include <queue>

#include <set>

#include <map>

#include <stack>

#include <math.h>

//#include "stdc++.h"

#define ll long long

#define int64 long long

#define mem(x,y) memset(x,y,sizeof(x))

#define ull unsigned long long

#define pb push_back

#define INF 0x7f7f7f7f

#define lson l, mid, rt<<1

#define rson mid+1, r, rt<<1|1

#define pi 3.141592653589793238462

#define stdio std::ios::sync_with_stdio(false)

#define zero(x) (((x)>0?(x):-(x))<eps)



using namespace std;



inline bool nextDouble(double &num) {

    char in;

    double Dec = 0.1;

    bool IsN = false, IsD = false;

    in = getchar();

    if (in == EOF) return false;

    while (in != '-' && in != '.' && (in < '0' || in > '9'))

        in = getchar();

    if (in == '-') {

        IsN = true;

        num = 0;

    } else if (in == '.') {

        IsD = true;

        num = 0;

    } else num = in - '0';

    if (!IsD) {

        while (in = getchar(), in >= '0' && in <= '9') {

            num *= 10;

            num += in - '0';

        }

    }

    if (in != '.') {

        if (IsN) num = -num;

        return true;

    } else {

        while (in = getchar(), in >= '0' && in <= '9') {

            num += Dec * (in - '0');

            Dec *= 0.1;

        }

    }

    if (IsN) num = -num;

    return true;

}

inline bool nextLongDouble(long double &num) {

    char in;

    long double Dec = 0.1;

    bool IsN = false, IsD = false;

    in = getchar();

    if (in == EOF) return false;

    while (in != '-' && in != '.' && (in < '0' || in > '9'))

        in = getchar();

    if (in == '-') {

        IsN = true;

        num = 0;

    } else if (in == '.') {

        IsD = true;

        num = 0;

    } else num = in - '0';

    if (!IsD) {

        while (in = getchar(), in >= '0' && in <= '9') {

            num *= 10;

            num += in - '0';

        }

    }

    if (in != '.') {

        if (IsN) num = -num;

        return true;

    } else {

        while (in = getchar(), in >= '0' && in <= '9') {

            num += Dec * (in - '0');

            Dec *= 0.1;

        }

    }

    if (IsN) num = -num;

    return true;

}

inline bool nextInt(int &num) {

    char in;

    bool IsN = false;

    in = getchar();

    if (in == EOF) return false;

    while (in != '-' && (in < '0' || in > '9')) in = getchar();

    if (in == '-') {

        IsN = true;

        num = 0;

    } else num = in - '0';

    while (in = getchar(), in >= '0' && in <= '9') {

        num *= 10, num += in - '0';

    }

    if (IsN) num = -num;

    return true;

}

inline bool nextLong(ll &num) {

    char in;

    bool IsN = false;

    in = getchar();

    if (in == EOF) return false;

    while (in != '-' && (in < '0' || in > '9')) in = getchar();

    if (in == '-') {

        IsN = true;

        num = 0;

    } else num = in - '0';

    while (in = getchar(), in >= '0' && in <= '9') {

        num *= 10, num += in - '0';

    }

    if (IsN) num = -num;

    return true;

}

inline bool blank(char ch) {

    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';

}

inline void read(char *s) {

    char ch = getchar();

    for (; blank(ch); ch = getchar());

    for (; !blank(ch); ch = getchar()) * s++ = ch;

    *s = 0;

}

const int maxn = 1e2 + 5;

const int maxm = 2e6 + 5;

const int mod =  1e9;

const int seed = 10007;

const double eps = 1e-6;

int a[4],x,c[4];

int dp[4][20005];



int main() {

    for(int i=1;i<=3;scanf("%d",&a[i++]));

    c[1]=500,c[2]=100,c[3]=50;

    scanf("%d",&x);

    mem(dp,0);

    dp[0][0]=1;

    for(int i=1;i<=3;i++){

        for(int j=0;j<=x;j++){

            int num = j/c[i];

            num=min(num,a[i]);

            for(int k=0;k<=num;k++){

                dp[i][j]+=dp[i-1][j-k*c[i]];

            }

        }

    }

    printf("%d\n",dp[3][x]);

    return 0;

}

/*

for(x:i) if(ans[x][j]=0) ans[i][j]=1

for(x:i) if(ans[x][j]=1)

*/
