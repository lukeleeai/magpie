#include "stdc++.h"

using namespace std;

typedef signed long long ll;



#undef _P

#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<(to);x++)

#define FORR(x,arr) for(auto& x:arr)

#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

#define ALL(a) (a.begin()),(a.end())

#define ZERO(a) memset(a,0,sizeof(a))

#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------



int K;

int N;

int A[1501][1501];

void check(int N) {

	set<vector<int>> S[1002];

	int x,y;

	FOR(y,N) FOR(x,N) {

		vector<int> V;

		V.push_back(A[(y+1)%N][x]);

		V.push_back(A[(y+N-1)%N][x]);

		V.push_back(A[y][(x+1)%N]);

		V.push_back(A[y][(x+N-1)%N]);

		sort(ALL(V));

		S[A[y][x]].insert(V);

	}

	

	FOR(x,K) if(S[x].size()!=1) {

		cout<<"NG "<<x<<" "<<S[x].size()<<endl;

	}

	

}



void solve() {

	int i,j,k,l,r,x,y; string s;

	

	cin>>K;

	

	if(K==1) {

		cout<<1<<endl;

		cout<<1<<endl;

		return;

	}

	

	int step=((K+3)/4)*4;

	N=step/2;

	int cnt[505]={};

	FOR(y,N) FOR(x,N) {

		r=(x+y)%N;

		if(y%2) r+=N;

		if(r>=K) r-=N;

		A[y][x]=r;

	}

	

	check(N);

	cout<<N<<endl;

	FOR(y,N) {



		FOR(x,N) cout<<A[y][x]+1<<" ";

		cout<<endl;

	}

	

	

	

}





int main(int argc,char** argv){

	string s;int i;

	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);

	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);

	cout.tie(0); solve(); return 0;

}
