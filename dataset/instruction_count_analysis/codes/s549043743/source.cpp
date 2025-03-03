#include "stdc++.h"

using namespace std;

typedef long long ll;

//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

 

/* attention

    long longのシフト演算には気をつけよう

    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも

*/



ll N, A, B;

vector<ll> h(100005);



bool check(int k){

    ll tmp = 0;

    for(int i=0; i<N; i++){

        if(h[i]-B*k <= 0) continue;

        tmp += max(0LL,(h[i]-B*k-1)/(A-B) + 1);

    }



    if(tmp <= k) return true;

    else return false;

}



int solve(){

    int left = 0, right = 1000000000;

    int mid;

    while(right - left > 1){

        mid = (left+right)/2;

        bool v = check(mid);

        if(v) right = mid;

        else left = mid;

    }



    return right;

}



int main(){

    cin >> N >> A >> B;

    for(int i=0; i<N; i++) cin >> h[i];



    cout << solve() << endl;

}