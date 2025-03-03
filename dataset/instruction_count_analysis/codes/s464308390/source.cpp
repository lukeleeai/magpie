#include<iostream>

#include<algorithm>

#include<vector>

#include<stack>

#include <cmath>

#include <limits>

#include<set>

#include <iomanip>

#include <queue>

#include <string>

#pragma GCC optimize("Ofast")

using namespace std;

const long long INF=20000000000;

//setprecision(2) <<



const int MOD = 1000000007;



long long max(long long a,long long b){

	if(a<b)return b;

	else return a;	

}

long long min(long long a,long long b){

	if(a>b)return b;

	else return a;	

}

long long gcd(long long a,long long b){

	if(a<b)swap(a,b);

	if(a%b==0)return b;

	else return gcd(a%b,b);

}



long long lcm(long long a,long long b){

	return a*b/gcd(a,b);

}





long long getDigit(long long n){

	if(n==1)return 1;

	else return log10(n)+1;

}



class Point{

public:

	long long x;

	long long y;

};

long long N,M;

vector<long long>X(100006,0);

bool isOK(long long N){

	string s=to_string(N);

	set<char>set;

	for(int i=0;i<s.length();i++){

		set.insert(s[i]);

	}

	return set.size()==1;

}

int main(){

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	long long N,M;

	cin>>N>>M;

	vector<long long>dp(M+1,0);

	for(int i=0;i<N;i++){

		long long K;

		cin>>K;

		for(int k=0;k<K;k++){

			long long a;

			cin>>a;

			dp[a]++;

		}

	}

	long long ans=0;

	for(int i=0;i<=M;i++){

		if(dp[i]==N)ans++;

	}

	cout<<ans<<endl;

}
