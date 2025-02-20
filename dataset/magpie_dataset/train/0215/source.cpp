#include<iostream>

#include<algorithm>

using namespace std;

int n,key,cnt,ans;

int t[1000001];

int main(){

  while(cin>>n&&n){

    for(int i=0;i<n;i++)cin>>t[i];

    t[n]=ans=-1;

    sort(t,t+n);

    key=t[0];

    cnt=1;

    for(int i=1;i<=n;i++){

      if(key==t[i])cnt++;

      else{

	if(cnt>n/2)ans=key;

	key=t[i];

	cnt=1;

      }

    }

    if(ans==-1)cout<<"NO COLOR"<<endl;

    else cout<<ans<<endl;

  }

  return 0;

}