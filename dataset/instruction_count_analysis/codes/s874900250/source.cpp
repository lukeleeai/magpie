#include <iostream>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <string>

#include <limits.h>

#include <float.h>

#include <numeric>

#include <queue>



using namespace std;



typedef long long ll;

typedef pair<int, int> P;



const ll mod = 1000000007;

ll fact[1000200];

ll invfact[1000200];



inline ll take_mod(ll a){

    return (a % mod + mod) % mod;

}



inline ll add(ll a, ll b){

    return take_mod(a+b);

}



inline ll sub(ll a, ll b){

    return take_mod(a-b);

}





inline ll mul(ll a, ll b){

    return take_mod(a * b);

}



inline ll pow(ll x, ll n){

    ll res = 1LL;

    while(n > 0){

        if(n & 1) res = mul(res, x);

        x = mul(x, x);

        n >>= 1;

    }

    return res;

}



ll mod_inv(ll x){

    return pow(x, mod-2);

}



// nは上限

void make_fact(ll n){

    fact[0] = 1;

    ll res = 1;

    for(int i = 1; i <= n; i++){

        fact[i] = res;

        res = mul(res, i+1);

    }

}



// nは上限

void make_invfact(ll n){

    invfact[0] = 1;

    invfact[n] = mod_inv(fact[n]);

    for(int i = n-1; i >= 1; i--){

        invfact[i] = mul(invfact[i + 1], i + 1);

    }

}



ll perm(ll n, ll k){

    return mul(fact[n], invfact[n-k]);

}



ll comb(ll n, ll k){

    return mul(mul(fact[n], invfact[n-k]), invfact[k]);

}



#define fs first

#define sc second



map<char, char> m1;

map<char, char> m2;



int main(){

    ll N, M;

    cin >> N >> M;

    make_fact(200200);

    make_invfact(200200);



    vector<ll> prime_list;

    ll prime = 2, count = 0;

    while(M > 1){

        while(M % prime == 0){

            M /= prime;

            count++;

        }

        if(count > 0){

            prime_list.push_back(count);

        }

        count = 0;

        prime += 1;

    }



    ll res = 1;

    for(int i = 0; i < prime_list.size(); i++){

        res = mul(comb(prime_list[i]+N-1, prime_list[i]), res);

    }

    cout << res % mod << endl;



    return 0;

}