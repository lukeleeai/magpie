#include<cstdio>

using namespace std;

const int mod=1e9+7;

int n,k;

long long f[2005][2005],s[2005],ans;

long long ksm(long long a,long long b)

{

  long long ans=1;

  while(b)

  {

  	if(b&1)  ans=ans*a%mod;

  	a=a*a%mod;b>>=1;

  }

  return ans;

}

int main()

{

  //FILE *fi,*fo;

  //fi=fopen("forget.in","r");

  //fo=fopen("forget.out","w"); 

  scanf("%d%d",&n,&k);f[0][n+1]=1;

  for(int i=1;i<=k;i++)

  {

	s[n+1]=f[i-1][n+1];  

	for(int j=n;j>=1;j--)  s[j]=(f[i-1][j]+s[j+1])%mod;

	for(int j=1;j<=n-i+1;j++)  f[i][j]=s[j];

  }

  if(n>k)  ans=(((f[k][1]-f[k-1][1]+mod)%mod)*ksm(2,n-k-1))%mod;

  else  ans=(f[k][1]-f[k-1][1]+mod)%mod;

  printf("%lld",ans);

  return 0;

}