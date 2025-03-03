#include<cstdio>

#include<iostream>

#include<algorithm>

#include<cmath>

long long pos[100010],sum[100010];

using namespace std;

int main()

{

	int n,k,x;long long ans=- int(1e9);

	cin>>n>>k;

	for(int i=1;i<=n;i++)

	{

		cin>>x;

		sum[i]=sum[i-1]+x;

		pos[i]=x<0?pos[i-1]:pos[i-1]+x;

	//	cout<<sum[i]<<" "<<pos[i]<<endl;

	}

	for(int i=k;i<=n;i++)

	{

		long long s=pos[n]-(pos[i]-pos[i-k]);//Çø¼äÍâË¢Õý 

		if(sum[i]-sum[i-k]>0) s+=sum[i]-sum[i-k];//Èç¹ûÇø¼äºÍ´óÓÚÁã¾ÍË¢ºÚ 

		ans=max(s,ans);

	}

	cout<<ans;

	return 0; 

}