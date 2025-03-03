#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<string>

#include<vector>

#include<list>

#include<set>

#include<map>

#include<queue>

#include<stack>

#include<cctype>

#include<climits>

#include<bitset>

#include"stdc++.h"

#define ld long double

#define ll long long int

#define ull unsigned long long int

#define rep(i,n) for(i=0;i<n;i++)

#define fin(ans) cout<<(ans)<<endl

#define mem(array,n) memset(array,n,sizeof(array));

#define INF INT_MAX

#define vi vector<int>

#define vc vector<char>

#define vs vector<string>

#define vpii vector<pair<int,int> >

#define vvi vector<vector<int> >

#define vvc vector<vector<char> >

#define vvs vector<vector<string> >

#define P 1000000007

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const long long LLINF=1LL<<60;

//set<int>::iterator it;



int dp[110][2][1010];

int ans=0;

int rec(string s,int k=0,bool tight=true,int sum=0){

//	cout<<k<<" "<<sum<<endl;

	if(k==s.size()){

		ans=max(ans,sum);

		return ans;

	}

	int x=s[k]-'0';

	int r=tight? x:9;

	int res=dp[k][tight][sum];

	if(res>=0)return res;

	res=0;

	for(int i=max(0,r-1);i<=r;i++){

		res=max(res,rec(s,k+1,tight&&i==r,sum+i));

	}

	return res;

}



int main(void){ios::sync_with_stdio(false);cin.tie(0);

//////////////////////////////////////////////////////

	

	string s;

	cin>>s;

	mem(dp,-1);

	

	cout<<rec(s)<<endl;

	

	

	

	

	

//////////////////////////////////////////////////////

return 0;}


















