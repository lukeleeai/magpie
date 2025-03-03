#include"stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=(a); i<(b); i++)

int G[505][505], n;

void solve(int l, int r, int t){

	if(l+1 == r) return;

	int m = (l+r) / 2;

	rep(i,l,m) rep(j,m,r) G[i][j] = t;

	solve(l,m,t+1); solve(m,r,t+1);

}



int main(){

	scanf("%d", &n);

	solve(0,n,1);

	rep(i,0,n) rep(j,i+1,n) printf("%d%c", G[i][j], j == n-1 ? '\n' : ' ');

}