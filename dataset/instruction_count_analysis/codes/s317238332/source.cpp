#define ALL(obj) (obj).begin(), (obj).end()

 

#include <iomanip>

#include <iostream>

#include <fstream>

#include <cstdio>

#include <cmath>

#include <vector>

#include <string>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <deque>

#include <bitset>

#include <algorithm>

#include <complex>

#include <array>

#include <functional>

 

using namespace std;

typedef long long ll;

const ll INF = 1e18;

 

ll N;

ll K;

 

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cin >> N >> K;

    vector<ll> p(N);

 

    for (ll i=0; i<N; i++) {

        cin >> p[i];

    }

    

    vector<ll> table(200001);

    ll sum = 0;

    

    for (ll i=1; i<=200000; i++) {

        sum += i;

        table[i] = sum;

    }

    

    double answer = 0.0;

 

    if (N==1) {

        cout << (double)table[p[0]] / (double)p[0] << endl;

        return 0;

    }

    

    if (N==2) {

        if (K==1) {

            double a = (double)table[p[0]] / (double)p[0];

            double b = (double)table[p[1]] / (double)p[1];

            if (a > b) {

                cout << a << endl;

                return 0;

            } else {

                cout << b << endl;

                return 0;

            }

        } else {

            double ans = (double)table[p[0]] / (double)p[0] + (double)table[p[1]] / (double)p[1];

            cout << ans << endl;

            return 0;

        }

    }

    

    for (ll j=0; j<K; j++) {

        answer += (double)table[p[j]] / (double)p[j];

    }

    

    double max = answer;

    for (ll i=K; i<N; i++) {

        double left = (double)table[p[i-K]] / (double)p[i-K];

        double right = (double)table[p[i]] / (double)p[i];

        double tmp = answer + right - left;

        if (max < tmp) {

            max = tmp;

        }

        answer = tmp;

    }

    

    cout << setprecision(12) << max << endl;

    

    return 0;

}
