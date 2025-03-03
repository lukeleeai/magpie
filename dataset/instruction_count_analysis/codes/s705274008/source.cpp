#include<stdio.h>

int main(){

	long long t=0,sum=0,n,k[200010],s[200010];

	scanf("%lld",&n);

	for(int i=1;i<=n;i++){

		scanf("%lld%lld",&k[i],&s[i]);

		sum+=k[i]*s[i];

		t+=s[i];

	}

	if(sum%9==0) printf("%lld",sum/9+t-2);

	else printf("%lld",sum/9+t-1);

	return 0;

}