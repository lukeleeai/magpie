#include <cstdio>

#include <algorithm>

using namespace std;

int n,m,f[100005],g[100005];



void zzk(int L,int R){

	for (int k=1,kk,kkk,a,Max,Min; k<=m && k<=R;){

		// k<=kk<=(l-1)/a

		a=(L-1)/k;

		if (a==0) Max=99999999; else Max=(L-1)/a; Min=k-1;

		kk=R/(a+1);

		kk=min(kk,Max); kk=max(kk,Min);

		f[k]++; f[kk+1]--;

		k=Max+1;

	}

}



int main(){

	scanf("%d%d",&n,&m);

	for (int i=1,l,r; i<=n; i++){

		scanf("%d%d",&l,&r);

		zzk(l,r);

	}

	for (int i=1; i<=m; i++) g[i]=g[i-1]+f[i],printf("%d\n",g[i]);

}



/*

3 3

1 2

2 3

3 3



*/