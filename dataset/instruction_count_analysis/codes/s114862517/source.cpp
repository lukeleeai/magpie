#include"stdc++.h"

#define MAXN 100005

#define mod 1000000007

typedef long long ll;

using namespace std;

vector<ll> arr,book,dp;

int main(){

    ll n;

    cin >> n;

    arr.assign(n,0);

    book.assign(MAXN,0);

    dp.assign(MAXN,0);

    char x;

    for(ll i=0;i<n;i++){

        cin >> x;

        arr[i]=x-'a'+1;

    }

    sort(arr.begin(),arr.end());

    for(ll i=1;i<=n;i++){

        if(!book[arr[i-1]]){

            dp[i]=(2*dp[i-1]+1)%mod;

        }

        else{

            int t=book[arr[i-1]];

            dp[i]=(dp[i-1]*2%mod+mod-dp[t-1]%mod)%mod;

        }

        book[arr[i-1]]=i;

    }

    cout << dp[n]%mod << '\n';

    return 0;

}
