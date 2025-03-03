#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

typedef long long ll;





std::vector<ll> enum_div(ll n);



int main() {



    ll N, M;



    cin >> N >> M;



    vector<ll> v = enum_div(M);



    sort(v.begin(), v.end(), greater<ll>());



    ll ans = 1;



    for (ll i = 0; i < v.size(); i++) {

        if (v[i] * N <= M) {

            ans = v[i];

            break;

        }

        

    }





    cout << ans << '\n';



}



std::vector<ll> enum_div(ll n)//nの約数を列挙

{

    vector<ll> ret;

    for (ll i = 1; i * i <= n; i++) {



        if (n % i == 0) {



            ret.push_back(i);



            if (i * i != n) {

                ret.push_back(n / i);

            }

        }

    }

    

    return ret;

}
