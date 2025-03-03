#include "stdc++.h"

using namespace std;



typedef unsigned long long ull;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;

const ull mod = 1e9 + 7;

#define REP(i,n) for(int i=0;i<(int)n;++i)



//debug

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



template < typename T >

void vprint(T &v){

	REP(i, v.size()){

		cout << v[i] << " ";

	}

	cout << endl;

}



vector<ll> gr(102020);

vector<ll> G[102020];



void merge(ll x, ll y){

	if(G[gr[x]].size() < G[gr[y]].size()){

		swap(x, y);

	}

	ll gx = gr[x];

	ll gy = gr[y];

	REP(i, G[gy].size()){

		gr[G[gy][i]] = gx;

		G[gx].push_back(G[gy][i]);

	}

	return;

}



int main(){

	ll N, M;

	cin >> N >> M;

	vector<pll> list(M);

	REP(i, M){

		cin >> list[i].first >> list[i].second;

	}

	vector<ll> result(M);

	ll tmp = N*(N-1)/2;

	result[0] = tmp;

	REP(i, N+1){

		G[i].push_back(i);

		gr[i] = i;

	}

	REP(i, M-1){

		ll x = list[M-1-i].first;

		ll y = list[M-1-i].second;

		if(gr[x]!=gr[y]){

			tmp -= (G[gr[x]].size() * G[gr[y]].size());

			merge(x, y);

		}

		result[i+1] = tmp;

	}

	REP(i, M){

		cout << result[M-1-i] << endl;

	}

    return 0;

}