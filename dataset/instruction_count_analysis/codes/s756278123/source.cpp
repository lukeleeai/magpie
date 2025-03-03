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

ll N;

int main()

{

    cin >> N;

    ll l = 0LL;

    ll r = 0;

    for (int i = 0; i < N; ++i)

    {

        cin >> a[i];

    }

    for (int i = 0; i < N; ++i)

        r += a[i];



    ll minV = INF;



    for (int i = 0; i < N - 1; ++i)

    {

        l += a[i];

        r -= a[i];

        minV = min(minV, abs(l - r));

    }

    cout << minV << endl;

    return 0;

}