#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<int,pii> ipii;

const int N = 1e5;





int find_par(int x, int *par){

	if(par[x] == x) return x;

	return par[x] = find_par(par[x],par);

}



int par[N+5];

int global_par[N+5];

vector<ipii> edge;



int n,q;

ll m;

int cnt[N+5];

int maksi[N+5];

bool pake[N+5];



int main(){

	memset(pake,0,sizeof(pake));

	scanf("%d%lld%d",&n,&m,&q);

	int unused = n;

	for(int i=1;i<=q;i++){

		int a,b,c;

		scanf("%d%d%d",&a,&b,&c);

		a++;

		b++;

		if(!pake[a]){

			unused--;

			pake[a]=1;

		}

		if(!pake[b]){

			unused--;

			pake[b]=1;

		}

		edge.push_back(make_pair(c,make_pair(a,b)));

	}

	unique(edge.begin(),edge.end());

	sort(edge.begin(),edge.end());

	for(int i=1;i<=n;i++) par[i] = i,cnt[i]=1, global_par[i] = i;

	int valid = 1;

	int cnt2 = 0;

	ll gabung = n;

	

	for(int i=0;i<q;i++){

		if(edge[i].first == 0){

			int pa = find_par(edge[i].second.first,par);

			int pb = find_par(edge[i].second.second,par);

			if(pa != pb){

				par[pa] = pb;

				gabung--;

			}

		} else {

			if(m == n-1)valid = 0;

			int pa = find_par(edge[i].second.first,par);

			int pb = find_par(edge[i].second.second,par);

			if(pa == pb){

				valid = 0;

				break;

			}

			

		}

	}

	

	if(!valid){

		printf("No\n");

		return 0;

	}

	

	ll cnM = gabung * (gabung-3) / 2;

	if(m <= n+cnM) printf("Yes\n");

	else printf("No\n");

	return 0;

}