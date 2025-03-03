#include<cstdio>

#include<algorithm>

using namespace std;

int main(){

  int n,m;

  long x,y,z,s[8][1000],sum,ans=0;

  scanf("%d %d",&n,&m);

  for(int i=0;i<n;i++){

    scanf("%ld %ld %ld",&x,&y,&z);

    s[0][i]=x+y+z;

    s[1][i]=x+y-z;

    s[2][i]=x-y+z;

    s[3][i]=x-y-z;

    s[4][i]=-1*x+y+z;

    s[5][i]=-1*x+y-z;

    s[6][i]=-1*x-y+z;

    s[7][i]=-1*x-y-z;

  }

  for(int i=0;i<8;i++)

    sort(s[i],s[i]+n);

  for(int i=0;i<8;i++){

    sum=0;

    for(int j=n-1;j>=n-m;j--)

      sum+=s[i][j];

    ans=max(ans,sum);

  }

  printf("%ld\n",ans);

}