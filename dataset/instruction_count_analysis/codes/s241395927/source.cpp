#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

//long long mo = 1e9 + 7;

typedef long long ll;



int main(){

    ll N,D,A;

    cin >> N >> D >> A;

    vector<pair<ll,ll>> X(N);

    vector<ll> L(200100);

    rep(i,N){

        cin >> X[i].first >> X[i].second;

    }

    sort(X.begin(), X.end());

    ll cnt = 0;

    D *= 2;

    queue<pair<ll,ll>> que;

    ll total = 0;

    for(int i=0;i<N;i++){

        while(!que.empty() && que.front().first < X[i].first){

            total -= que.front().second;

            que.pop();

        }

        if(X[i].second > total){

            ll damage = X[i].second - total;

            ll num = (damage + A - 1) / A;

            cnt += num;

            total += num*A;

            que.push(make_pair(X[i].first + D, num*A));

        }

    }





    cout << cnt  << endl;

}
