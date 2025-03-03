#include "stdc++.h"

#define REP(i,a,b) for(int i=(a);i<(b);i++)

#define RREP(i,a,b) for(int i=(a);i>=(b);i--)

#define pq priority_queue

#define P pair<int,int>

#define P2 pair<int,P>

#define P3 pair<int,P2>

typedef long long ll; typedef long double ld;

using namespace std;

const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};

const ll LINF=1e18;

const ld PI=abs(acos(-1));

int x,y;

string s;



int main(){

	cin >> s >> x >> y;

	

	bool f=true;

	int c=0,c2=0;

	vector<int> vec,vec2; vec.push_back(0); vec2.push_back(0);

	REP(i,0,s.size()){

		if(f and s[i]=='T') vec2.push_back(0),c2++,f=false;

		else if(!f and s[i]=='T') vec.push_back(0),c++,f=true;

		else if(f and s[i]=='F') vec[c]++;

		else if(!f and s[i]=='F') vec2[c2]++;

	}

	

	bool dp[c+10][8010*2+1]={}; dp[0][8010+vec[0]]=true;

	REP(i,0,vec.size()-1){

		int a=vec[i+1];

		RREP(j,8010*2,0){

			if(dp[i][j] and j-a>=0) dp[i+1][j-a]=true;

			if(dp[i][j] and j+a<8010*2) dp[i+1][j+a]=true;

		}

	}

	

	bool dp2[c2+10][8010*2+1]={}; dp2[0][8010+vec2[0]]=true;

	REP(i,0,vec2.size()-1){

		int a=vec2[i+1];

		RREP(j,8010*2,0){

			if(dp2[i][j] and j-a>=0) dp2[i+1][j-a]=true;

			if(dp2[i][j] and j+a<8010*2) dp2[i+1][j+a]=true;

		}

	}

	

	if(dp[c][8010+x] and dp2[c2][8010+y]) cout << "Yes" << endl;

	else cout << "No" << endl;

	return 0;

}
