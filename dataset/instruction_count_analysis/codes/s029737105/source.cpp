#include <iostream>

#include <cstring>

#include <string>

#include <cstdio>

#include <cmath>

using namespace std;

const int N = 2e5 + 100;

int n, ans, m;

int main()

{

    cin >> n >> m;

    for (int i = 1; i <= sqrt(m); i++)

    {

        if (m % i == 0)

        {

            if (i >= n)

                ans = max(m/i, ans);

            if (m / i >= n)

                ans = max(i, ans);

        }

    }

    cout << ans << endl;

}
