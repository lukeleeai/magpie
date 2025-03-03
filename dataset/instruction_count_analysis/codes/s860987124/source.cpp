#include <stdio.h>

#define LL long long

LL ans,b;

int n,prime[2000],not_prime[10010],tot;

void linear_shaker(int x){

	int i,j;

	for(i=2;i<=x;i++){

		if(!not_prime[i])prime[++tot]=i;

		for(j=1;prime[j]*i<=x;j++){

			not_prime[prime[j]*i]=1;

			if(i%prime[j]==0)break;

		}

	}

}

int main(){

	int i,n,cnt,x,j;

	linear_shaker(10000);

	ans=0;

	scanf("%d",&n);

	for(i=1;i<=n;i++){

		x=i,b=1;

		for(j=1;prime[j]*prime[j]<=x;j++){

			cnt=0;

			if(x%prime[j]==0){

				while(x%prime[j]==0)x/=prime[j],cnt++;

				b*=(cnt+1);

			}

		}

		if(x>1)b*=2;

		ans+=b*i;

	}

	printf("%lld\n",ans);

	return 0;

}