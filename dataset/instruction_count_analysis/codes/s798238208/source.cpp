#include<cstdio>

int main(){

	long long n,ans=0;scanf("%lld",&n);

	if(n%2)return puts("0"),0;

	for(n/=10;n;n/=5)ans+=n;

	return printf("%lld\n",ans),0;

}