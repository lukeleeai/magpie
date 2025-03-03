#include"stdc++.h"

using namespace std;

#define N 510

int n,c,a[N],ct;

double r,f[N][(1<<7)];

int main(){

	cin>>n>>c;

	for(int i=0;i<n;i++)

		cin>>a[i];

	sort(a,a+n);

	do{

		memset(f,0,sizeof(f));

		f[a[n-1]*n][0]=1;

		for(int i=0;i<=n*c;i++)

			for(int j=i;j<=n*c;j++)

				for(int s=0;s<(1<<(n-1));s++)

					if(i%n&&!(s&(1<<(i%n-1)))&&f[j][s]){

						f[min(n*c,max(j,i+a[i%n-1]*n))][s+(1<<(i%n-1))]+=f[j][s];

					}

		r+=f[n*c][(1<<(n-1))-1];

		ct++;

	}while(next_permutation(a,a+n-1));

	printf("%.15lf",(double)r/ct/pow(c,n-1));

}