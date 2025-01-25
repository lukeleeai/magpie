#include "stdc++.h"

using namespace std;



// Hi there, I'm Dondo.  It might be long time no see!

// I managed to solve this last problem by myself, so I removed some 

// stupid macros I used in order to show off this code!

// 

// I put the tree into the array so that each subtree corresponds to a

// subsequence of it.  I want to do two operations to an array: get a value 

// of an element, and add some value to the subsequence of the array.

// In order to do that, I used BIT (=bit<T>) which calculates the 

// cumulative sum of a subsequence (=sbit). 

// I used 3 sbit's : one attains the cost from the root to each vertex (not 

// considering the free path) (=csm), one attains how much you have to minus

// the cost when calculating (=dsm), and one attains the count how many 

// how many changes has been done(=qry).  Please take at look at the code 

// if you want to see the detail. (I don't want to explain the solution in

// English anymore :-) )

//

// Please say hi to everyone.  Bye!

//

// P.S. I didn't use long long to the bit although the cost can be up to

// 10^10, but I've got AC.  Isn't the testcase weak or did I just make

// some mistake in consideration?



// Types ///////////////////////////////////////////////////////////////////////

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<pii> vpii;

 

// Loop & Iteration ////////////////////////////////////////////////////////////

#define FOR(i, a, b) for(int i=a; i<b; i++)

#define REP(i, n) FOR(i, 0, n)



#define PB push_back

#define MP make_pair

 

// BIT /////////////////////////////////////////////////////////////////////////

template<

	typename T = int

>

class bit{

public:

	T *bit_arr;

	int size;

 

	bit(int n){

		size = n;

		bit_arr = new T[n];

		fill(bit_arr, bit_arr+n, 0);

	}

 

	~bit(){

		delete bit_arr;

	}

 

	T sum(int a){

		T ret = 0;

		while(a){

			ret+=bit_arr[a];

			a-=a&-a;

		}

		return ret;

	}

 

	T sum(int a, int b){

		return sum(b)-sum(a);

	}

 

	T get(int a){

		return sum(a, a+1);

	}

 

	void add(int a, T x){

		a++;

		while(a<size){

			bit_arr[a]+=x;

			a+=a&-a;

		}

	}

 

	void set(int a, T x){

		add(a, x-get(a));

	}

};

typedef bit<ll> bll;

 

#define N 112345

#define LO 18

class sbit{

public:

	bit<int> b;

	sbit() : b(N){

	}

	void add(int l, int r, int x){

		b.add(l, x);

		b.add(r, -x);

	}

	int get(int i){

		return b.sum(i+1);

	}

};



int n, k;

vpii path[N];

int f[N]; // original node index -> on the list

int c[N]; // size of subtree

int d[N]; // depth in tree

int p[N][LO]; // parent doubling

// int dmm[N];

sbit csm, dsm, qry;

char buf[10];



void dfs(int nw, int par, int dep, int ind){

	// printf("dfs(nw=%d, par=%d, dep=%d, ind=%d)\n", nw, par, dep, ind);

	f[nw]=ind;

	d[ind]=dep;

	p[ind][0]=par;

	FOR(i, 1, LO) p[ind][i]=p[p[ind][i-1]][i-1];

	int sm=1;

	REP(i, path[nw].size()){

		pii &pr=path[nw][i];

		if(f[pr.first]==par) continue;

		dfs(pr.first, ind, dep+1, ind+sm);

		csm.add(ind+sm, ind+sm+c[ind+sm], pr.second); // <-pr.first?

		if(pr.second%k==0){

			dsm.add(ind+sm, ind+sm+c[ind+sm], pr.second);

			// dmm[ind+sm]=pr.second;

		}

		sm+=c[ind+sm];

	}

	c[ind]=sm;

}



int lsc(int x, int y){

	if(d[x]<d[y]) swap(x, y);

	int dif=d[x]-d[y];

	REP(i, LO) if(dif&(1<<i)) x=p[x][i];

	// printf(" %d %d\n", x, y);

	if(x==y) return x;

	int ret=0;

	for(int i=LO-1; i>=0; i--){

		// printf("(%d, %d)->(%d, %d)\n", x, y, p[x][i], p[y][i]);

		if(p[x][i]==p[y][i]) ret=p[x][i];

		else{

			x=p[x][i];

			y=p[y][i];

		}

	}

	return ret;

}



int clc(int x){

	int q;

	while((q=qry.get(x))){

		int y=x;

		for(int i=LO-1; i>=0; i--){

			if(qry.get(p[y][i])==q) y=p[y][i];

		}

		dsm.add(y, y+c[y], -(dsm.get(y)-dsm.get(p[y][0])));

		int r=csm.get(y)-csm.get(p[y][0]);

		if(r%k==0){

			dsm.add(y, y+c[y], r);

		}

		qry.add(y, y+c[y], -(qry.get(y)-qry.get(p[y][0])));

	}

	return csm.get(x)-dsm.get(x);

}



int main(){

	scanf("%d%d", &n, &k);

	fill(f, f+N, -1);

	// fill(dmm, dmm+N, 0);

	REP(i, n-1){

		int a, b, c;

		scanf("%d%d%d", &a, &b, &c);

		path[a].PB(MP(b, c));

		path[b].PB(MP(a, c));

	}

	dfs(0, 0, 0, 0);

	// REP(i, 20) printf("%2d ", i); LN;

	// REP(i, 20) printf("%2d ", c[i]); LN;

	// REP(i, 20) printf("%2d ", d[i]); LN;

	// REP(i, 20) printf("%2d ", csm.get(i)); LN;

	// REP(i, 20) printf("%2d ", dsm.get(i)); LN;

	int q;

	scanf("%d", &q);

	REP(iqq, q){

		int x, y;

		scanf("%s%d%d", buf, &x, &y);

		if(buf[0]=='s'){

			x=f[x];

			y=f[y];

			int z=lsc(x, y);

			int ans=clc(x)+clc(y)-2*clc(z);

			printf("%d\n", ans);

		}else if(buf[0]=='a'){

			x=f[x];

			if(x){

			 	csm.add(x, x+c[x], y);

				qry.add(x, x+c[x], 1);

			}

			csm.add(x+1, x+c[x], y);

			qry.add(x+1, x+c[x], 1);

		}

	}

}