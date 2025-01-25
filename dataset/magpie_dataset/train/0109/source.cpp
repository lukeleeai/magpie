#include"stdc++.h"

using namespace std;

int n;

int a[100005];

int x[100005];

int y[100005];



int main(){

  scanf("%d",&n);

  for(int i=0;i<n;i++){

    cin>>a[i];

  }



  memset(x,-1,sizeof(x));

  memset(y,-1,sizeof(y));

  

  int ans=0;

  for(int i=0;i<n;i++){

    int p=i,c=0;

    while(x[p]==-1){

      x[p]=c++;

      y[p]=i;

      p=(p+a[p])%n;

    }

    if(y[p]==i)ans+=(c-x[p]);

  }



  cout<<ans<<endl;

  return 0;

}