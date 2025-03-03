//#pragma GCC optimize(3, "Ofast", "inline")

#include "stdc++.h"

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

const double eps = 1e-8;

int n,x;

int main()

{

    scanf("%d", &n);

    int ans = 0;

    for (int i = 0; i < n; ++i)

        scanf("%d", &x), ans ^= x;

    if (ans)

        puts("No");

    else

        puts("Yes");

    return 0;

}