#include"stdc++.h"

using namespace std;

int im[100010]={};

int main(){

  int n;

  cin>>n;

  for(int i=0;i<n;i++){

    int a,b;

    cin>>a>>b;

    im[a]++;

    im[b+1]--;

  }

  int ans;

  for(int i=1;i<=n+2;i++){

    im[i]+=im[i-1];

    if(im[i-1]>=i-2)ans=i-2;

  }

  cout<<ans<<endl;

  return 0;

}


