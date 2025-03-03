#include "stdc++.h"



#define int long long



using namespace std;



const int N = 5e5 + 5;

const int base = 317;

const int mod = 1e9 + 2277;



string s;

int Hash[N], pw[N], n;

bool pref[N], suff[N];



void buildHash(){

    s = "#" + s;

    pw[0] = 1;

    for (int i = 1; i < N; i++) pw[i] = (pw[i - 1] * base) % mod;

    Hash[0] = 0;

    for (int i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * base + s[i]) % mod;

}



int get (int l, int r) {

    return ((1LL * Hash[r] - 1LL * Hash[l - 1] * pw[r - l + 1]) % mod + mod) % mod;

}



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    cin >> s;

    n = s.length();



    bool same = true;

    for (int i = 0; i < n; i++) if (s[i] != s[0]) same = false;

    if (same) {

        cout << n << "\n" << 1;

        return 0;

    }



    buildHash();

    memset(pref, 0, sizeof(pref));

    memset(suff, 0, sizeof(suff));



    for (int i = 1; i <= n; i++) {

        for (int j = i * 2; j <= n; j = j + i) {

            if (get(1, i) == get(j - i + 1, j)) pref[j] = true;

            else break;

        }

    }



    for (int i = 1; i <= n; i++) {

        for (int j = n - i * 2 + 1; j >= 1; j = j - i) {

            if (get(j, j + i - 1) == get(n - i + 1, n)) suff[j] = true;

            else break;

        }

    }



    if (!pref[n]) return cout << 1 << "\n" << 1, 0;

    int ans = 0;

    for (int i = 1; i < n; i++) if (!pref[i] && !suff[i + 1]) ans++;

    cout << 2 << "\n" << ans;

    return 0;

}
