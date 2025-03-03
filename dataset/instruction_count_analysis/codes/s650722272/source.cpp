#include<cstdio>

#include<cstring>

const long long mod=1e9+7;

long long matmod(long long val,long long k){

	long long ret=1ll;

	for(;k;k>>=1){

		if(k&1) ret=(val*ret)%mod;

		val=(val*val)%mod;

	}

	return ret;

}

void add(long long &des,long long sor){des+=sor;des%=mod;return ;}

char s[5005];

int n;

long long f[2][5005];

int main(){

	//freopen("keyboard.in","r",stdin);

	//freopen("keyboard.out","w",stdout);

	scanf("%d",&n);

	scanf("%s",s);

	int len=strlen(s);

	if(len>n){puts("0");return 0;}

	long long mul=matmod(2ll,len);

	f[0][0]=1ll;

	long long ans=f[0][len];

	for(int i=1;i<=n;i++){

		f[i&1][0]=(f[(i-1)&1][0]+f[(i-1)&1][1])%mod;

		for(int j=1;j<=i;j++){

			f[i&1][j]=0; 

			add(f[i&1][j],f[(i-1)&1][j-1]*2ll);

			add(f[i&1][j],f[(i-1)&1][j+1]);

		}

		add(ans,f[i&1][len]);

	}

	long long tmp=matmod(mul,mod-2ll);

	long long newans=f[n&1][len]*tmp%mod;

	printf("%lld\n",newans);

	return 0;

}