#include "stdc++.h"



#define rr(i, b)    for (int i = 0; i < int(b); i++)

#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]

#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl

#define bug(x) cout << #x << " " << x << endl

#define ll long long

#define vii vector <int>



using namespace std;



bool check(string s) {



    int l = 0;

    int r = s.size()/2;



    while(r != s.size()) {

        if(s[l] != s[r]) {

            return false;

        }

        l++;

        r++;

    }



    return true;

}



vector<long long> fac(20 + 1);



void fact() {

    fac[0] = 1;

    for(int i = 1; i <= 20; i++) {

        fac[i] = fac[i - 1] * i;

    }

}



void solve() {

    int x;

    cin >> x;



    cout << !x << endl;

}

 

int main(){

    cin.tie(0);

    ios_base::sync_with_stdio(false);

    //fact();

    int t = 1;

    //cin >> t;



    while(t--)

    solve();

    return 0;

}