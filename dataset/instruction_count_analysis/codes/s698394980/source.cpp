#include<iostream>

#include<iostream>

using namespace std;

int main(){

  int n;string s;cin>>n>>s;

  int a[200010]={},b[200010]={};

  for(int i=0;i<n;++i){

	a[i+1]=a[i];

	if(s[i]=='#')a[i+1]++;

  }

  for(int i=0;i<n;++i){

	b[i+1]=b[i];

	if(s[n-i-1]=='.')b[i+1]++;

  }

  int ans=300000;

  for(int i=0;i<=n;++i){

	ans=min(ans,a[i]+b[n-i]);

  }

  cout<<ans<<endl;

}
