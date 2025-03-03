#include <cstdio>

long long  a,b,c,d,i,j,k,x,y,z,ans;

long long f[100005];

int main(){

	ans=0;

	f[0]=0;

	scanf("%lld %lld",&a,&b);

	for (i=1;i<=a;i++) scanf("%lld",&f[i]);

	for (i=1;i<=a;i++){

		if (f[i]+f[i-1]>b){

			c=f[i]+f[i-1]-b;

			ans+=c;

			f[i]-=c;	

		}

	}

	printf("%lld\n",ans);

}