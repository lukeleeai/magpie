#include<cstdio>

#include<algorithm>

long long n,k,ans,h[200005];

int main(){

	scanf("%lld%lld",&n,&k);

	for(int i=0;i<n;++i)scanf("%lld",&h[i]);

	std::sort(h,h+n);

	for(int i=0,j=n-k;i<j;++i)ans+=h[i];

	printf("%lld\n",ans);

	return 0;

}