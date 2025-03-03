#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

using namespace std;

typedef long long LL;

inline LL in()

{

    LL x = 0, flag = 1; char ch = getchar();

    while (ch < '0' || ch > '9') {if (ch == '-') flag = -1; ch = getchar();}

    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();

    return x * flag;

}

LL n, m;

int main()

{

    n = in();

    m = in();

    cout << (n - 1) * (m - 1);

    return 0;

}