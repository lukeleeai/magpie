#include "stdc++.h"

#define f first

#define s second



using namespace std;



typedef long long ll;



int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    priority_queue <ll> nums;

    for(int i=0; i<n; i++){

        ll tmp; cin >> tmp;

        nums.push(tmp);

    }

    while(m--){

        ll tmp = nums.top();

        nums.pop();

        nums.push(tmp/2);

    }

    ll ans = 0;

    while(!nums.empty()){

        ans += nums.top();

        nums.pop();

    }

    cout << ans << '\n';

    return 0;

}
