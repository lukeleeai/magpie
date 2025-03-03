#include "stdc++.h"



using namespace std;



#define int long long

long long m, s, ans = 1e12;



long long f(long long b, long long n){

    if(b == 1) return 0;

    if(n < b) return n;

    else return f(b, n / b) + n % b;

}



signed main(){

    cin.tie(0), ios::sync_with_stdio(0);

    cin >> m >> s;

    if(m == s){

        cout << m + 1;

        return 0;

    }

    for(int i = 2; i*i <= m; i++){

        if(f(i, m) == s)

            ans = min (ans,i);

    }

    for(int i = 2; i*i <= s; i++){

        if(f(i, m) == s)

            ans = min (ans,i);

    }

    if(m > s){

        for(int i = 1; i*i <= m - s; i++){

            int pointer = (m - s)/i + 1;

            if(f(i, m) == s)

                ans = min(ans,i);

            if(f(pointer, m) == s)

                ans = min(ans,pointer);

        }

    }

    if(ans != 1e12) {cout << ans; exit(0);}

    cout << "-1\n";

}
