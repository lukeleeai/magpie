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



struct UnionFind {

    vector<int> par;

    

    UnionFind(int n) : par(n, -1) { }

    void init(int n) { par.assign(n, -1); }

    

    int root(int x) {

        if (par[x] < 0) return x;

        else return par[x] = root(par[x]);

    }

    

    bool issame(int x, int y) {

        return root(x) == root(y);

    }

    

    bool merge(int x, int y) {

        x = root(x); y = root(y);

        if (x == y) return false;

        if (par[x] > par[y]) swap(x, y); // merge technique

        par[x] += par[y];

        par[y] = x;

        return true;

    }

    

    int size(int x) {

        return -par[root(x)];

    }

};



int main(){

	ll N, M;

	cin >> N >> M;

	ll tmp = N*(N-1)/2;

	vector<ll> res;

	res.push_back(tmp);

	UnionFind uf(N);

	vector<ll> X(M), Y(M);

	REP(i, M){	

		cin >> X[i] >> Y[i], X[i]--, Y[i]--;

	}

	REP(i, M){

		ll A = X[M-1-i];

		ll B = Y[M-1-i];

		if(!uf.issame(A, B)){

			ll sa = uf.size(A);

			ll sb = uf.size(B);

			tmp -= sa*sb;

			uf.merge(A, B);

		}

		res.push_back(tmp);

	}

	REP(i, M){

		cout << res[M-1-i] << endl;

	}

    return 0;

}