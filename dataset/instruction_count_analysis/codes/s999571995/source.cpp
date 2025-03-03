#include<iostream>

#include<algorithm>

using namespace std;



int main(){

  int n,k,i;

  long long int x,y,z,a[8][1000],sum=0,ans=0;

  cin>>n>>k;

  for(i=0;i<n;i++){

    cin>>x>>y>>z;

    a[0][i]=x+y+z;

    a[1][i]=x+y-z;

    a[2][i]=x-y+z;

    a[3][i]=x-y-z;

    a[4][i]=-x+y+z;

    a[5][i]=-x+y-z;

    a[6][i]=-x-y+z;

    a[7][i]=-x-y-z;

  }

  for(i=0;i<8;i++){

    sort(a[i],a[i]+n);

    sum=0;

    for(int j=n-1;j>=n-k;j--)

      sum+=a[i][j];

    if(ans<sum)

      ans=sum;

  }

  cout << ans<<endl;

}