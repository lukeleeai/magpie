#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

#include <string>

#include <queue>

#include <utility>

#include <map>

#include <bitset>

#include <numeric>

#define ll long long

using namespace std;

using p = pair<ll, ll>;

ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位

ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位



int main(void) {

    string s, t;

    cin >> s >> t;

    ll count = 0;

    ll len = 0;

    bool ok = false;

    ll c = 0;

    if(s.length()>=t.length()){

        for(ll i = 0; i <= s.length()-t.length(); i++){

            //cout << i << endl;

            for(ll j = 0; j < t.length(); j++){

                if(s[i+j]!=t[j] && s[i+j]!='?') break;

                if(j==t.length()-1) {

                    ok = true;

                    c = i;

                }

            }

        }

    }

    string ans;

    if(ok==true){

        for(ll i = 0; i < c; i++) {

            if(s[i]!='?')ans += s[i];

            else ans+= 'a';



        }

        ans += t;

        for(ll i = c+t.length(); i < s.length(); i++){

            if(s[i]!='?')ans += s[i];

            else ans+= 'a';

        }

        cout << ans << endl;

    }

    else if(ok==false)

        cout << "UNRESTORABLE" << endl;

    return 0;

}
