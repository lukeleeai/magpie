#include<iostream>

#include<cstdio>

#include<stack>

#include<queue>

#include<set>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<map>

#define max_n

using namespace std;

typedef long long ll;

map<int,int> mp;



int main ()

{

	ll m,n,ans=0;

	scanf("%lld %lld",&n,&m);

	for(int i=0;i<m;i++)

	{

		ll t1,t2;

		scanf("%lld %lld",&t1,&t2);

		mp[t1]++;

		mp[t2]++;

		if(mp[t1]%2==0&&mp[t2]%2==0)

			ans+=2;

		if(mp[t1]%2==1&&mp[t2]%2==1)

			ans-=2;

	}

	if(ans==0)

		cout<<"YES"<<endl;

	else

		cout<<"NO"<<endl;

	

	return 0;

}