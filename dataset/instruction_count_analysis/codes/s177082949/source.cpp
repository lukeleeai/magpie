#include <stdio.h>

#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define REP(i,n)  FOR(i,0,n)

int a[20];

int n;



bool DFS(int k, int m, double r){

	int s=ceil(a[k]*(1-r));

	int e=ceil(a[k]*(1+r));

	for(int p=((s-1)/m+1)*m;p<e;p+=m)

		if(k==n-1)return true;

		else if(DFS(k+1,p,r))return true;

	return false;

}



int main(){

	scanf("%d",&n);

	REP(i,n)scanf("%d",&a[i]);

	double u=1.0,l=0.0;

	REP(i,30){

		double m=(u+l)*0.5;

		if(DFS(0,1,m))u=m;

		else l=m;

	}

	printf("%.9f\n",u);

	return 0;

}