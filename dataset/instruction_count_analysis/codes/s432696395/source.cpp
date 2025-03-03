#include<cstdio>

using namespace std;

long long n,m,ans;

int main()

{

  scanf("%lld%lld",&n,&m);ans=m;

  for(int i=1;i<=n-1;i++)  ans*=(m-1);

  printf("%lld\n",ans);

  return 0;

}