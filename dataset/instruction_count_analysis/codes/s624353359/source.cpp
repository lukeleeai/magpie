#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

#include <queue>

using namespace std;

using ll = long long;

#define INF 1LL << 59

//西暦⇒時代の歴



ll a[201000];

ll N, K;

ll GCD(ll a, ll b)

{

    if (a < b)

        swap(a, b);



    if (b == 0)

        return a;

    return GCD(b, a % b);

}

int main()

{

    cin >> N >> K;

    ll maxV = 0;

    for (int i = 0; i < N; ++i)

    {

        cin >> a[i];

        maxV = max(maxV, a[i]);

    }

    if (N == 1)

    {

        if (a[0] == K)

            cout << "POSSIBLE" << endl;

        else

            cout << "IMPOSSIBLE" << endl;

        return 0;

    }

    ll d = GCD(a[0], a[1]);



    for (int i = 2; i < N; ++i)

    {

        d = GCD(d, a[i]);

    }

    if (K % d == 0 && maxV >= K)

        cout << "POSSIBLE" << endl;

    else

        cout << "IMPOSSIBLE" << endl;

    return 0;

}