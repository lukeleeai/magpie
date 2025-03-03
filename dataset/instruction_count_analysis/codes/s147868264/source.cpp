#include <stdio.h>

#include <cmath>

#include <algorithm>

#include "stdc++.h"

const int maxn = 1e5 + 10;

using namespace std;

int main()

{

    int n, x;

    long long a[maxn] = {0};

    cin >> n >> x;

    long long  count = 0;

    for (int i = 0; i < n; i++)

        scanf("%lld", &a[i]);

    for (int i = 0; i < n - 1; i++)

    {

        if (a[i] > x)

        {

            count += (a[i] - x);

            a[i] = x;

        }

        if (a[i] + a[i+1] > x)

        {

            count += (a[i+1] + a[i] - x);

            a[i+1] = a[i+1] - (a[i+1] + a[i] - x);

        }

    }

    cout << count << endl;

    return 0;

}