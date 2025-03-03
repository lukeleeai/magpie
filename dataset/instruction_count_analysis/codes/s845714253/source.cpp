#include "bits/stdc++.h"



using namespace std;

using ll=long long;

using ull=unsigned long long;



typedef pair<int,int>Pi;

typedef pair<long long,long long>P;

typedef pair<long long,P>PP;

typedef pair<P,P>PPP;



const long long MOD=1e9+7;

const long long INF=5e18;

const int di[4]={1,0,-1,0};

const int dj[4]={0,1,0,-1};



#define fr first

#define sc second

#define pb push_back

#define eb emplace_back

#define ALL(x) (x).begin(),(x).end()

#define ALLR(x) (x).rbegin(),(x).rend()



int n,a,b,mx,le;



void input(){

	cin>>n;

	return;

}



void solve(){

	for(int i=0;i<n;i++){

		cin>>a>>b;

		if(a>=mx)mx=a,le=b;

	}

	cout<<le+mx<<endl;

	return;

}



int main(){

	input();

	solve();

	return 0;

}