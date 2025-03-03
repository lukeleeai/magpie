#include<algorithm>

#include<cstdio>

using namespace std;

int main(){

  int i;

  int d;

  while(scanf("%d",&d),d){

    int m,n;

    scanf("%d%d",&m,&n);

    int a[100001];

    a[0]=0;

    a[m]=d;

    for(i=1;i<m;++i)

      scanf("%d",a+i);

    sort(a,a+m+1);

    int sm=0;

    for(i=0;i<n;++i){

      int p,q;

      scanf("%d",&p);

      q=upper_bound(a,a+m+1,p)-a;

      sm+=min(p-a[q-1],a[q]-p);

    }

    printf("%d\n",sm);

  }

  return 0;

}