#include "stdc++.h"



using namespace std;



#define ll long long



const int INF = 1e9+9999;



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int n, k, arr=0;

    string s;

    cin >> n >> k >> s;

    s.push_back('W');

    for (int i=0; i<n; ++i)

        if (s[i] != s[i+1])

            ++arr;

    int ans = n - arr;

    while (k && arr) {

        if (arr == 2)

            ++ans, ++arr;

        else

            ans+=2;

        --k;

        arr-=2;

    }

    cout << min(ans, n-1);

}
