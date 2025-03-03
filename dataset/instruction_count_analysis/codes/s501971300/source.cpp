#include <cstdio>

long long a,b,c,d,i,j,k,x,y,z,ans;

int main(){

	ans=0;

	scanf("%lld %lld",&a,&b);

	for (i=0;i<=a;i++){

		x=i;

		c=b-x;

		if ((c>=0) and (c<=a)){

			ans+=c+1;

		}

		if ((c>a) and (c<=2*a)){

			ans+=2*a-c+1;

		} 

	}

	printf("%lld\n",ans);

}