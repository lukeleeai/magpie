#include<algorithm>

#include<cstdio>

using namespace std;

int main(){

  int i;

  int n,m,h,k;

  while(scanf("%d%d%d%d",&n,&m,&h,&k),n||m||h||k){

    pair<int,int> a[1000];

    for(i=0;i<n;++i)

      scanf("%d",&(a[i].second));

    pair<int,int> b[100000];

    for(i=0;i<m;++i)

      scanf("%d%d",&(b[i].second),&(b[i].first));

    sort(b,b+m);

    int c[1000];

    for(i=0;i<n;++i)

      c[i]=i;

    for(i=0;i<m;++i){

      int p=c[b[i].second-1];

      c[b[i].second-1]=c[b[i].second];

      c[b[i].second]=p;

      b[i]=make_pair(c[b[i].second],c[b[i].second-1]);

    }

    for(i=0;i<n;++i)

      a[i].first=c[i];

    sort(a,a+n);

    int sm=0;

    for(i=0;i<k;++i)

      sm+=a[i].second;

    int mn=sm;

    for(i=0;i<m;++i){

      if(b[i].first<k&&b[i].second>=k&&a[b[i].first].second>a[b[i].second].second)

	mn=min(mn,sm-a[b[i].first].second+a[b[i].second].second);

      if(b[i].first>=k&&b[i].second<k&&a[b[i].first].second<a[b[i].second].second)

	mn=min(mn,sm+a[b[i].first].second-a[b[i].second].second);

    }

    printf("%d\n",mn);

  }

  return 0;

}