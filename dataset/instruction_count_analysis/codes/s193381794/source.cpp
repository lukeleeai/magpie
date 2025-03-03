#include <iostream>

#include <queue>

#include <cmath>



using namespace std;

using ll = long long;

using ld = long double;



#define st first

#define nd second



const int MAXN = 2e5 + 5;



int n;

ll dp[MAXN], h[MAXN];



ll f(int j,  int i) {

    return dp[j] + (h[i] - h[j]) * (h[i] - h[j]);

}



ld intersection(int i, int j) {

    //return (ld) (f(j, 0) - f(i,  0)) / (ld) (2 * (h[j] - h[i]));

    return (ld) ((h[j] * h[j] + dp[j]) - h[i] * h[i] - dp[i]) / (2 * (h[j] - h[i]));

}



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    ll C;

    cin >> n >> C;

    for (int i = 1; i<= n; i++) {

        cin >> h[i];

    }



    deque<int> Q = {1};

    int m = 1;

    for (int i = 2; i <= n; i++) {

        while (Q.size() > 1 and f(Q[1], i) < f(Q[0], i)) {

            m--;

            Q.pop_front();

        }



        dp[i] = f(Q[0], i) + C;



        while (Q.size() > 1 and intersection(Q[Q.size() - 2], i) <= intersection(Q[Q.size() - 2], Q.back())) {

            m--;

            Q.pop_back();

        }

        Q.push_back(i);

    }



    cout << dp[n] << "\n";

}
