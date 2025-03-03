#include<cstdio>

#include<cmath>

#include<algorithm>

using namespace std;

const double pi=acos(-1);

int n,x[101],y[101];

double p[201];

int pp;

double Max(double a,double b){return a>b?a:b;}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);

	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++)if(i!=j) p[++pp]=atan2(y[j]-y[i],x[j]-x[i]);

		sort(p+1,p+pp+1);

		for(int j=1;j<=pp;j++) p[pp+j]=p[j]+pi+pi;

		double mx=0;

		for(int j=1;j<=pp;j++) mx=max(mx,pi-p[j+pp-1]+p[j]);

		printf("%.8lf\n",mx/pi/2);

		pp=0;

	}

}