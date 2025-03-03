#include<cstdio>

int k,a[100005];

long long maxn=2,minn=2;

int main(){

	scanf("%d",&k);

	for(int i=1;i<=k;++i) scanf("%d",&a[i]);

	for(int i=k;i>=1&&maxn>=minn;--i){

		if(minn%a[i]) minn=minn/a[i]*a[i]+a[i];

		maxn=(maxn/a[i]+1)*a[i]-1;

	}

	if(maxn>=minn) printf("%lld %lld\n",minn,maxn);

	else puts("-1");

	return 0;

}