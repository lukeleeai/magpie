#include "stdc++.h"

using namespace std;

#define MOD 1000000007

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)

#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}

#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}

typedef long long ll;

typedef pair<int, int> P;

ll gcd(int x, int y){ return y?gcd(y, x%y):x;}

ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

typedef tuple<int, int, int, int> tset;



int coinmap[510][510] = {0};



int main()

{

    int h, w;

    cin >> h >> w;



    rep(i, h)rep(j, w){

        int tmp; cin >> tmp;

        coinmap[i][j] = tmp%2;

    }



    // rep(i, h){

    //     rep(j, w){

    //     cout <<coinmap[i][j];

    //     }

    //     cout << endl;

    // }



    vector<tset> sousa;

    rep(i, h)rep(j, w){

        if (coinmap[i][j]){

            if (i == h-1 && j == w-1) continue;

            tset tmp;

            coinmap[i][j] ^= 1;

            if (j != w-1){

                coinmap[i][j+1] ^= 1;

                tmp = make_tuple(i+1, j+1, i+1, j+2);                

            } else {

                coinmap[i+1][j] ^= 1;

                tmp = make_tuple(i+1, j+1, i+2, j+1);                

            }

            sousa.push_back(tmp);

        }

    }



    cout << sousa.size() << endl;

    rep(i, sousa.size()){

        cout << get<0>(sousa[i]) << " " << get<1>(sousa[i]) << " "  << get<2>(sousa[i]) << " "  << get<3>(sousa[i]) << endl;

    }



}