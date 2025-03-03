#include<cstdio>

#define Mod 998244353

int gcd(int x,int y){return y?gcd(y,x%y):x;}

int n,a,b;

long long sum,k,t,inv[300100],C[300100];

int main(){

	scanf("%d%d%d%lld",&n,&a,&b,&k);

	inv[1]=1;for(int i=2;i<=n;++i)inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;

	C[0]=1;for(int i=1;i<=n;++i)C[i]=C[i-1]*(n-i+1)%Mod*inv[i]%Mod;

	t=gcd(a,b);a/=t;b/=t;

	if(k%t!=0){puts("0");return 0;}else k/=t;

	for(long long i=0;i<=b;++i)if((k-a*i)%b==0){t=i;break;}

	for(long long i=t;i*a<=k&&i<=n;i+=b){

		if((k-i*a)/b<=n)sum=(sum+C[i]*C[(k-i*a)/b])%Mod;

	}

	printf("%lld\n",sum);

	return 0;

}