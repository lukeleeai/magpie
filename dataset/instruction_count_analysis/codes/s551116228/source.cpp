#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>

#define ll long long

#define MOD 1000000007

using namespace std;

ll FastM(ll a, ll p, ll m){

	if(p == 0) return 1;

	ll r = a % m;

	ll k = 1;

	while(p > 1){

		if((p & 1) != 0){

			k = (k * r) % m;

		}

		r = (r * r) % m;

		p >>= 1;

	}

	return (r * k) % m;

}

int main()

{

    int n;

    cin>>n;

    int a[100005];

    int cnt[100005]={0};

    ll ans = 0;

    for(int i = 0; i < n; i++){

        cin>>a[i];

        cnt[a[i]]++;

    }

    for(int i = n-1; i > 0; i--){

        if(cnt[i] > 2){

            printf("0");

            return 0;

        }

    }

    if(n % 2 == 0){

        if(cnt[0] > 2){

            printf("0");

            return 0;

        }

        ans = FastM(2, n/2, MOD);

    }

    else {

        if(cnt[0] > 1){

            printf("0");

            return 0;

        }

        ans = FastM(2, (n-1)/2, MOD);

    }

    cout<<ans;

    return 0;

}
