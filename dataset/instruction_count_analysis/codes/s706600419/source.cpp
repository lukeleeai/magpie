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

using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

typedef double db;



#define fr first

#define sc second

#define pb push_back

#define rep(i,x) for(ll i=0;i<x;i++)

#define rep1(i,x) for(ll i=1;i<=x;i++)

#define rrep(i,x) for(ll i=x-1;i>=0;i--)

#define rrep1(i,x) for(ll i=x;i>0;i--)

const ll INF=0xffffffffffffff;

ll N,M,Q;

ll D[100000];

ll d[100000];

ll U[200000],V[200000];

ll R[200000];

bool ansin[100000];

ll anum[200000];

vector<ll> G[100000];

vector<ll> G2[100000];

priority_queue<ll,vector<ll> ,greater<ll > >  q;







bool mov[200000];

int main()

{

	cin>>N>>M>>Q;

	rep(i,M){

		cin>>U[i]>>V[i];

		U[i]--;

		V[i]--;

		G[V[i]].pb(U[i]);

		G[U[i]].pb(V[i]);

	}

	rep(i,Q){

		cin>>R[i];

		R[i]--;

		mov[R[i]]=1;

	}

	fill(D,D+N,INF);

	D[0]=0;

	

	q.push(0);

	while(!q.empty()){

		ll x=q.top();

		q.pop();

		rep(i,G[x].size()){

			if(D[G[x][i]]>D[x]+1){

				D[G[x][i]]=D[x]+1;

				q.push(G[x][i]);

			}

		}

	}

	ll cnt=1;

	fill(d,d+N,INF);

	d[0]=0;

	ansin[0]=1;

	rep(i,M){

		if(!mov[i]){

			G2[U[i]].pb(V[i]);

			G2[V[i]].pb(U[i]);

		}

	}

	q.push(0);

	while(!q.empty()){

		ll x=q.top();

		q.pop();

		rep(i,G2[x].size()){

			if(d[G2[x][i]]>d[x]+1){

				d[G2[x][i]]=d[x]+1;

				if(d[G2[x][i]]==D[G2[x][i]]&&!ansin[G2[x][i]]){

					ansin[G2[x][i]]=1;

					cnt++;

				}

				q.push(G2[x][i]);

			}

		}

	}

	anum[Q-1]=cnt;

	rrep1(i,Q-1){

		ll a=U[R[i]];

		ll b=V[R[i]];

		G2[a].pb(b);

		G2[b].pb(a);

		if(d[a]+1<d[b]){

			d[b]=d[a]+1;

			if(d[b]==D[b]&&!ansin[b]){

					ansin[b]=1;

					cnt++;

			}

			q.push(b);

		}

		else if(d[b]+1<d[a]){

			d[a]=d[b]+1;

			if(d[a]==D[a]&&!ansin[a]){

					ansin[a]=1;

					cnt++;

			}

			q.push(a);

		}

		while(!q.empty()){

			ll x=q.top();

			q.pop();

			rep(i,G2[x].size()){

			if(d[G2[x][i]]>d[x]+1){

					d[G2[x][i]]=d[x]+1;

					if(d[G2[x][i]]==D[G2[x][i]]&&!ansin[G2[x][i]]){

						ansin[G2[x][i]]=1;

						cnt++;

					}

					q.push(G2[x][i]);

				}

			}

		}

		anum[i-1]=cnt;

	}

	rep(i,Q) cout<<N-anum[i]<<endl;

}