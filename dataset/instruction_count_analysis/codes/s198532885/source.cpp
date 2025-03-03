#include <vector>

#include <algorithm>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <chrono> //1e+9??§?????? auto end= chrono::system_clock::now()-st;  cout<<end.count()%1e+9<<endl;

using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

typedef long double db;



#define fr first

#define sc second

#define pb push_back

#define rep(i,x) for(ll i=0;i<x;i++)

#define rep1(i,x) for(ll i=1;i<=x;i++)

#define rrep(i,x) for(ll i=x-1;i>=0;i--)

#define rrep1(i,x) for(ll i=x;i>0;i--)

struct edge{

	ll id,to;

};

vector<edge> G[100000];

bool over[200000];



ll N,M,Q;

P H[200000];

ll d[100000];

ll ans=0;

ll nyu[100000];

bool fuman[100000];

bool use[200000];



void is_gensho(ll v){

	nyu[v]--;

	if(nyu[v]==0){

		fuman[v]=1;

		ans++;

		rep(i,G[v].size()){

			edge e=G[v][i];

			if(d[e.to]==d[v]+1&&!over[e.id]){

				over[e.id]=1;

				is_gensho(e.to);

			}

		}

	}

}



int main()

{

	cin>>N>>M>>Q;

	rep(i,M){

		cin>>H[i].fr>>H[i].sc;

		H[i].fr--; H[i].sc--;

		G[H[i].fr].pb(edge{i,H[i].sc});

		G[H[i].sc].pb(edge{i,H[i].fr});

	}

	memset(d,-1,sizeof(d));

	queue<ll> q;

	d[0]=0;

	q.push(0);

	while(!q.empty()){

		ll v=q.front();

		q.pop();

		rep(i,G[v].size()){

			edge e=G[v][i];

			if(d[e.to]==-1){

				d[e.to]=d[v]+1;

				q.push(e.to);

				nyu[e.to]++;

				use[e.id]=1;

			}

			else if(d[e.to]==d[v]+1){

				nyu[e.to]++;

				use[e.id]=1;

			}

		}

	}

	ll id,a,b;

	rep(i,Q){

		cin>>id;

		id--;

		if(!over[id]&&use[id]){	

			a=H[id].fr;

			b=H[id].sc;

			if(d[a]<d[b]) swap(a,b);

			is_gensho(a);

		}

		over[id]=1;

		cout<<ans<<endl;

	}

}