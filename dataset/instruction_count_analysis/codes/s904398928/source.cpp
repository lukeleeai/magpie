// D - Coloring Edges on Tree

#include "stdc++.h"

using namespace std;

#define rp(i,s,e) for(int i=(s);i<(e);++i)



const int cm = 1<<17;

char cn[cm], *ci = cn + cm, ct;

inline char getcha(){

	if(ci-cn == cm){ fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}



inline int getint(){

	int a = 0;

	if(ci-cn+16 > cm) while((ct=getcha()) >= '0') a = a*10 + ct - '0';

	else while ((ct=*ci++) >= '0') a = a*10 + ct - '0';

	return a;

}



const int dm = 1<<20;

char dn[dm], *di = dn;

inline void putint(int x){

	char c[10];

	int d; for(d=0; x; d++, x/=10) c[d] = x%10 + '0';

	for(int i=d-1; i>=0; --i) *di++ = c[i];

	*di++ = '\n';

}



#define NMAX 100000

int K = 1;

int C[NMAX+1];//child

int S[NMAX+1];//sibling

int colors[NMAX+1];



void dfs(int p, int p_color){

	for(int color=1, c=C[p]; c; c=S[c], color++){

		K = max(K, colors[c] = color==p_color? ++color: color);

		dfs(c, color);

	}

}



int main(){

	int N = getint();

	int Q[N];

	rp(i, 1, N){

		int p = getint(); Q[i] = getint();

		S[Q[i]] = C[p];

		C[p] = Q[i];

	}

	dfs(1, 0);

	putint(K);

	rp(i, 1, N) putint(colors[Q[i]]);

	fwrite(dn, 1, di - dn, stdout);

}