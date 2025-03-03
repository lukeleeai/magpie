#include"stdc++.h"

#define pii pair<int,int> 

#define mp make_pair

using namespace std;

const int mxn=2e4+4;

int A[mxn],B[mxn],X[mxn],n,cnt;

int ord[mxn],scc[mxn],mid;

set<pii>s;

bool used[mxn];

inline void dfs(int a,int x){

	int tx,po;

	if(a<=n)tx=X[a+n],po=a+n;

	else tx=X[a-n],po=a-n;

	used[a]=1;

	s.erase(mp(tx,po));

	for(;s.size();){

		set<pii>::iterator it=s.lower_bound(mp(x-mid+1,-1));

		if(it==s.end() or it->first>x+mid-1)break;

		int y=it->second;

		if(y==a){

			it++;

			if(it==s.end() or it->first>x+mid-1)break;

			y=it->second;

		}

		if(y>n)dfs(y-n,X[y-n]);

		else dfs(y+n,X[y+n]);

	}

	ord[++cnt]=a;

}

inline void dfs2(int a,int x){

	scc[a]=cnt;

	s.erase(mp(x,a));

	int tx;

	if(a<=n)tx=X[a+n];

	else tx=X[a-n];

	for(;s.size();){

		set<pii>::iterator it2=s.lower_bound(mp(tx-mid+1,-1));

		if(it2==s.end() or it2->first>tx+mid-1)break;

		int y=it2->second;

		if(y==a-n or y==a+n){

			it2++;

			if(it2==s.end() or it2->first>tx+mid-1)break;

			y=it2->second;

		}

		dfs2(y,X[y]);

	}

}

inline bool check(int md){

	mid=md,s.clear();

	memset(used,0,sizeof(used));

	memset(scc,0,sizeof(scc));

	for(int i=1;i<=n*2;++i)s.insert(mp(X[i],i));

	cnt=0;

	for(int i=1;i<=n*2;++i)if(!used[i])dfs(i,X[i]);

	cnt=0;

	for(int i=1;i<=n*2;++i)s.insert(mp(X[i],i));

	for(int i=n*2;i;--i){

		if(!scc[ord[i]]){

			++cnt;

			dfs2(ord[i],X[ord[i]]);

		}

	}

	for(int i=1;i<=n;++i)if(scc[i]==scc[i+n])return 0;

	return 1;

}

int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(0),cout.tie(0);

	cin>>n;

	for(int i=1;i<=n;++i){

		cin>>A[i]>>B[i];

		X[i]=A[i],X[i+n]=B[i];

	}

	int lo=0,hi=1000000009,md;

	for(;lo<hi-1;){

		int md=lo+hi>>1;

		if(check(md))lo=md;

		else hi=md; 

	}

	cout<<lo<<endl;

	return 0;

}