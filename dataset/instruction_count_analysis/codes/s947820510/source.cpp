#include <stdio.h>

#define LL long long

int p[50],m[50],tot;//p[]记录质数,m[]记录幂次

int main(){

	LL n;

	int i,j,ans=0;

	scanf("%lld",&n);

	for(i=2;(LL)i*i<=n;i++)//注意此处不能写成for(i=2;i*i<=n;i++)

		if(n%i==0){

			p[++tot]=i;

			while(n%i==0)n/=i,m[tot]++;

		}

	if(n>1)p[++tot]=n,m[tot]=1;

	for(i=1;i<=tot;i++){

		j=1;

		while(1){

			if(m[i]>=j)ans++,m[i]-=j;

			else break;

			j++;

		}

	}

	printf("%d\n",ans);

	return 0;

}