#include<cstdio>

using namespace std;

long long n,f[200];  

int main()

{

  scanf("%lld",&n);f[0]=2;

  for(int i=1;i<=n;i++)  f[i]=f[i-1]*2+2;

  printf("%lld\n",f[n]);

  return 0;

}