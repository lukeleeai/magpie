#include "stdc++.h"

using namespace std;

#define finish(x) return cout << x << endl, 0

#define ll long long



const int N = 100001;



int n, mod = 1e9 + 7;

vector <int> a;



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> n;

    for(int i = 0 ; i < 2 * n ; i++){

        char c;

        cin >> c;

        a.push_back(c == 'W' ? 0 : 1);

    }

    int open = 0;

    int ans = 1;

    for(auto &i : a){

        if(open < 0) finish(0);

        if(((open & 1) ^ i) == 0){

            ans = 1LL * ans * open % mod;

            open--;

        }

        else open++;

    }

    if(open) finish(0);

    for(int i = 1 ; i <= n ; i++){

        ans = 1LL * ans * i % mod;

    }

    cout << ans << endl;

}
