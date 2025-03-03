#include<cstdio>

using namespace std;

int n,a[10005],b[10005];

long long sum1,sum2,delta,qwq;

int main()

{

  scanf("%d",&n);

  for(int i=1;i<=n;i++) 

    scanf("%d",&a[i]),sum1+=a[i];

  for(int i=1;i<=n;i++) 

    scanf("%d",&b[i]),sum2+=b[i];

  if(sum1>sum2)  {printf("No");return 0;}

  delta=sum2-sum1;

  for(int i=1;i<=n;i++)

    if(b[i]>a[i])

      qwq+=(b[i]+1-a[i])/2;

  if(qwq>delta)  printf("No");

  else  printf("Yes");

  return 0;

}