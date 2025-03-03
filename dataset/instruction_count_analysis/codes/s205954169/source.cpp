#include "stdc++.h"



#define int long long



using namespace std;



const int N = 5005;

const int mod = 1e9 + 7;



void add (int &x, int y) {

    x += y;

    x %= mod;

}



int dp[N], f[N];



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    int n;

    string s;

    cin >> n >> s;



    dp[0] = 1;

    for (int i = 0; i < n; i++) {

        memset(f, 0, sizeof(f));

        for (int j = 0; j <= i; j++) {

            add(f[j + 1], dp[j]);

            if (j) add(f[j - 1], 2 * dp[j]);

            else add(f[j], dp[j]);

        }



        for (int j = 0; j < N; j++) dp[j] = f[j];

    }



    cout << dp[s.length()];

    return 0;

}
