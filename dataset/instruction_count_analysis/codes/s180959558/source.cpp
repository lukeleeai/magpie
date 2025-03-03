#include "stdc++.h"

#define LL long long

#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define Re(a,b) memset(a,b,sizeof a)

#define F first

#define S second

#define MP make_pair

#define PB push_back

#define ALL(X) (X).begin(), (X).end()

#define FOR(I, A, B) for (int I = (A); I <= (B); I++)

#define REP(I, N) for (int I = 0; I < (N); I++)

#define PII pair<int,int>

#define PLL pair<LL,LL>

#define SZ(a) ((int)a.size())

using namespace std;

const int N=1e5+10;

int p[N];

int find(int x){

	if(x==p[x])return p[x];

	return p[x]=find(p[x]);

}

int n,k;

int a[N];

vector<int>g[N];

set<int>s[N];

int main(){

	cin>>n>>k;

	FOR(i,1,n)cin>>a[i],p[i]=i;

	REP(i,k){

		int u,v;cin>>u>>v;u=find(u),v=find(v);

		p[u]=v;

	}

	int t=0;

	FOR(i,1,n){

		find(i);

		if(s[p[i]].find(i)!=s[p[i]].end()){

			t++;

		}

		else s[p[i]].insert(i);

		

		if(s[p[i]].find(a[i])!=s[p[i]].end()){

			t++;

		}

		else s[p[i]].insert(a[i]);

		

	}

	cout<<t<<endl;



}