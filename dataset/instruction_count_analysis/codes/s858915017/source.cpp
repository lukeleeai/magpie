#include <vector>

#include <algorithm>

#include <utility>

#include <queue>

#include <cstdio>

#include <iostream>

#include <string>

#include <string.h>

#include <stdio.h>

#include <complex>



using namespace std;

typedef pair<int, int> PII;

typedef pair<int, PII> TIII;

#define PB push_back

#define MP make_pair

#define MT(a,b,c) MP(a, MP(b, c))

#define T1 first

#define T2 second.first

#define T3 second.second

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n)  FOR(i,0,n)

int a[20];

int n;



bool DFS(int k, int m, double r){

	int s = ceil(a[k]-a[k]*r);

	if(s==0)s=1;

	int e = ceil(a[k]+a[k]*r);

	for(int p = ((s-1)/m+1)*m; p<e; p+=m)

		if(k==n-1)return true;

		else if(DFS(k+1, p, r))return true;



	return false;

}



bool C(double r){

	return DFS(0,1,r);

}



int main(){

	cin>>n;

	REP(i,n)scanf("%d", &a[i]);

	double u=1.0, l=0.0;

	while(u-l>1e-9){

		double mid = (u+l)*0.5;

		if(C(mid))u=mid;

		else l = mid;

	}

	printf("%.10f\n", u);

	return 0;

}