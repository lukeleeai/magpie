#include <cstdio>

#include <climits>

#include <iostream>

#include <string>

#include <vector>

#include <set>

#include <cmath>

#include <stack>

#include <algorithm>

#include <iomanip>

#include <map>

#include <queue>

#include <functional>

#include <numeric>

#include <chrono>

#include <cstdlib>

using ll = long long;

using namespace std;



const ll MOD = 1e9 + 7;

const double pi = acos(-1);

typedef pair<int, int> P;

#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))

#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)

#define EPS 1e-4

#define OUTPUT(i) (cout << (ll)i << endl)

#define ALL(a) ((a).begin(), (a).end())



bool operator<(const pair<ll, ll> &a, const pair<ll, ll> &b)

{



    if (a.first == b.first)

        return a.second < b.second;



    return a.first < b.first;

}



ll gcd(ll a, ll b)

{

    if (b == 0)

        return a;

    return gcd(b, a % b);

}

vector<ll> v;

int main()

{

    cin.tie(0);

    ios::sync_with_stdio(false);



    //cout << fixed << setprecision(15);



    ll N, X;

    cin >> N >> X;



    REP(i, N)

    {

        ll a;

        cin >> a;

        v.push_back(a);

    }

    v.push_back(X);

    sort(v.begin(), v.end());



    ll ans = v[1] - v[0];

    for (int i = 2; i < N + 1; ++i)

    {

        ans = gcd(ans, v[i] - v[i - 1]);

    }

    cout << ans << endl;

    return 0;

}
