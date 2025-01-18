#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

using namespace std;

const int N=100005;

int f[N],a[N];

int main()

{

	int n,k;

	scanf("%d%d",&n,&k);

	memset(f,0x3f,sizeof(f));

	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	f[1]=0;

	for(int i=2;i<=n;i++){

		for(int j=1;j<=k;j++){

			if(i-j>=1) f[i]=min(f[i],f[i-j]+abs(a[i]-a[i-j]));

		}

	}

	printf("%d\n",f[n]);

}