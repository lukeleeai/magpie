#include"stdc++.h"

using namespace std;

typedef long long ll;





bool isprime(ll val) {

    if (val <= 1)return false;

    for (ll i = 2; i*i <= val; i++) {

        if (val%i == 0LL)return false;

    }

    return true;

}



signed main(){

    ios::sync_with_stdio(false);

	cin.tie(0);

    cout << fixed << setprecision(20);



    ll n;

    cin>>n;

    ll a[n],b[n+n];

    for(int i=0;i<n;i++){

        cin>>a[i];

    }

    for(int i=0;i<n;i++){

        cin>>b[i];

    }

    for(int i=0;i<n;i++){

        b[i+n] = b[i];

    }

    vector<ll> mod;

    for(ll i=1e9+7;i<1e9+30;i++){

        if(isprime(i)) mod.push_back(i);

    }

    ll mul[3];

    mul[0]=10007, mul[1]=10009, mul[2]=1007;

    ll h[3]={}, base[3]={1,1,1};

    ll x[3]={};

    for(int i=1;i<n;i++){

        for(int j=0;j<3;j++){

            if(i>1) base[j] = (base[j]*mul[j]) % mod[j];

            h[j] = (h[j]*mul[j] + (a[i]^a[i-1])) % mod[j];

            x[j] = (x[j]*mul[j] + (b[i]^b[i-1])) % mod[j];

        }

    }

    bool pos = true;

    for(int j=0;j<3;j++){

        if(h[j] != x[j]) pos = false;

    }

    vector<pair<ll,ll>> ans;

    if(pos){

        cout << 0 << " " << (a[0]^b[0]) << "\n";

    }

    for(int i=1;i<n;i++){

        bool pos = true;

        for(int j=0;j<3;j++){

            x[j] += mod[j] - (base[j] * (b[i]^b[i-1])) % mod[j];

            x[j] %= mod[j];

            x[j] = (x[j]*mul[j] + (b[n-1+i]^b[n-2+i])) % mod[j];

            if(x[j] != h[j]) pos = false;

        }

        if(pos){

            ans.push_back({n-i, (a[0]^b[i])});

        }

    }

    sort(ans.begin(),ans.end());

    for(auto i:ans){

        cout << i.first << " " << i.second << "\n";

    }

}