#include "stdc++.h"

using namespace std;

#define fix(f,n) std::fixed<<std::setprecision(n)<<f

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long int ll;

typedef unsigned long long int ull;

#define vi vector<int>

#define pii pair<int,int>

#define vii vector<pii>

#define max(a,b) ((a>b)?a:b)

#define min(a,b) ((a>b)?b:a)

#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)

#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)

#define REP(i,a,n) for(ll i=a;i<n;i++)

#define pb push_back

#define mp make_pair



int main(){

	fast;

	int test=1;

	//cin >> test;

	while(test--){

	    int n,k;

	    cin >> n >> k;

	    ll dp[n+1]={};

	    ll arr[n+1];

	    dp[1]=0;

	    for(int i=1 ; i<=n ; i++){

	        cin >> arr[i];

	    }

	    for(int i=2 ; i<=(k+1) && i<=n ; i++){

	        ll temp=1000000000000000000;

	        for(int j=(i-1) ; j>=1 ; j--){

	            temp=min(temp,dp[j]+abs(arr[j]-arr[i]));

	        }

	        dp[i]=temp;

	    }

	    for(int i=(k+2) ; i<=n ; i++){

	        ll temp=1000000000000000000;

	        for(int j=(i-1) ; j>=(i-k) ; j--){

	            temp=min(temp,dp[j]+abs(arr[j]-arr[i]));

	        }

	        dp[i]=temp;

	    }

	    cout << dp[n] << endl;

	}

	return 0;

}