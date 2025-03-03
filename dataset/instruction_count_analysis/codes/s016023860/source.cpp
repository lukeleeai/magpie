#include "stdc++.h"

#define ull uint64_t

#define ll long long int

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define mx5 100005

#define mx52 200005

#define mx6 1000005

#define mod 1000000007

#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



struct Line {

    ll m, c;

    double intersect(const Line& b) {

        return ((double)(c - b.c)) / (b.m - m);

    }



    ll eval(int x) {

        return m*x + c;

    }

};



Line getLine(ll dpi, ll hi) {

    return {-2*hi, hi*hi + dpi};

}



int main() {

    nfs

    int i, j, n;

    ll c, h[mx52];

    

    cin >> n >> c;

    for (i = 0; i < n; i++) {

        cin >> h[i];

    }

    

    ll dp[n] = {};

    deque <Line> options(1, getLine(dp[0], h[0]));

    for (int i = 1; i < n; i++) {

        while (options.size() > 1 && options[0].intersect(options[1]) < h[i])

            options.pop_front();

        dp[i] = options[0].eval(h[i]) + h[i]*h[i] + c;

        Line newLine = getLine(dp[i], h[i]);

        int li = options.size() - 1;

        while (li and options[li].intersect(options[li - 1]) >= options[li].intersect(newLine)) {

            options.pop_back();

            li--;

        }

        options.push_back(newLine);

    }

    cout << dp[n - 1];

}