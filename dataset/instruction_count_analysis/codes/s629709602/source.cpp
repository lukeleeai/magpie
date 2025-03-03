#include<cstdio>

#include<cstdlib>

#include<algorithm>

using namespace std;



const int N=100005;



int n,a[N];

int cnt[N];



int main(){

  int ans=0,tot=0;

  scanf("%d",&n);

  for (int i=1;i<=n;i++)

    scanf("%d",a+i),cnt[a[i]]++;

  for (int i=1;i<=100000;i++)

    if (cnt[i]){

      ans++;

      if (cnt[i]>3)

	cnt[i]=cnt[i]&1?1:2;

      if (cnt[i]==2)

	tot++;

    }

  if (tot&1)

    printf("%d\n",ans-1);

  else

    printf("%d\n",ans);

  return 0;

}
