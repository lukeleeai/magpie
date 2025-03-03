#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

#include <string>

#include <cstring>

#include <queue>

#include <iomanip>

#define ll long long

using namespace std;

using p = pair<ll, ll>;

ll dx[4] = {1, 0, -1, 0};

ll dy[4] = {0, 1, 0, -1};



int main(void){

    ll n, m;

    cin >> n >> m;

    ll s[m];

    char c[m];

    for(ll i = 0; i < m; i++){

        cin >> s[i] >> c[i];

    }

    bool check = true;

    double MIN = pow(10, n-1);

    if(MIN==1) MIN = 0;

    double MAX = pow(10, n);

    for(ll i = MIN; i < (ll)MAX; i++){

        string a = to_string(i);

        check = true;

        for(ll j = 0; j < m; j++){

            ll d = s[j]-1;

            if(a[d]!=c[j])

                check = false;

        }

        if(check == true){

            cout << i << endl;

            break;

        }

        if(check == false && i==MAX-1)

            cout << -1 << endl;

    }

    return 0;

}
