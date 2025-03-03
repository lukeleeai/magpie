#include<iostream>

#include<map>

#define rep(i,n) for(int i=0;i<n;i++)

#define foreach(i,c) for(__typeof(c.begin()) i=c.begin();i!=c.end();i++)

using namespace std;

void is(map<int,int> &mp,int n,int *a){

	for(int len=1;len<=n;len++)rep(i,n-len+1){

			int sum=0;

			rep(j,len)sum+=a[i+j];

			mp[sum]++;

		}

}

int main(){

	int m,n;

	while(cin>>n>>m,n){

		map<int,int> hm,wm;

		int h[1500],w[1500],ans=0;

		rep(i,n)cin>>h[i]; rep(i,m)cin>>w[i];

		is(hm,n,h); is(wm,m,w);

		foreach(i,hm)ans+=i->second*wm[i->first];

		cout<<ans<<endl;

	}

	return 0;

}