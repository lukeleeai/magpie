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

ll h[100005];



bool check(int k){

    ll cnt = 0;

    for(int i=0; i<N; i++){

        if(h[i]-k*B <= 0) continue;

        cnt += (h[i]-k*B-1)/(A-B) + 1;

    }



    if(cnt <= k) return true;

    else return false;

}



int solve(){

    ll left = 0, right = 1000000001;



    while(right - left > 1){

        ll mid = (left+right)/2;

        if(check(mid)) right = mid;

        else left = mid;

    }



    return right;

}





int main(){

    cin >> N >> A >> B;

    for(int i=0; i<N; i++) cin >> h[i];



    cout << solve() << endl;

}