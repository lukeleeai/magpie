#include<cstdio>

using namespace std;

int n,a,b,ans;

int main()

{

  scanf("%d",&n);

  for(int i=1;i<=n;i++)

    scanf("%d%d",&a,&b),ans=ans+b-a+1;

  printf("%d\n",ans);

  return 0;

}