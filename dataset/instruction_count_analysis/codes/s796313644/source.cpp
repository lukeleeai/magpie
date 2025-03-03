#include"stdc++.h"

using namespace std;

typedef long long ll;



const int maxi = 111111;

int a[maxi], k;



ll rem(ll val) {

    for(int i=1; i<=k; i++) {

        if(val % a[i] == 0) continue;

        else val -= val % a[i];

    }

    return val;

}



ll solveMax() {

    ll lo = 0, hi = 1e14, res = -1;

    int cnt = 60;



    while(cnt--) {

        ll mid = (lo + hi) / 2;

        if(rem(mid) == 2) res = mid;

        if(rem(mid) <= 2) lo = mid;

        else hi = mid;

    }



    return res;

}



ll solveMin() {

    ll lo = 0, hi = 1e14, res = -1;

    int cnt = 60;



    while(cnt--) {

        ll mid = (lo + hi) / 2;

        if(rem(mid) == 2) res = mid;

        if(rem(mid) < 2) lo = mid;

        else hi = mid;

    }



    return res;

}



int main() {

    cin>>k;



    for(int i=1; i <= k; i++) {

        cin>>a[i];

    }



    ll mx = solveMax(), mn = solveMin();



    if(mx == -1 || mn == -1) cout<<-1<<endl;

    else cout<<mn<<" "<<mx<<endl;

    return 0;

}
