#include<iostream>

using namespace std;

long long s,sum,n,a[1000001],b[1000001],cnt,ans;

long long f(long long x,long long y)

{

	if (x*y%9!=0)

		return x*y%9;

	if (x==0)

		return 0;

	return 9; 

} 

int main()

{

	cin>>n;

	for (int i=1;i<=n;++i)

	{

		cin>>a[i]>>b[i];

		ans+=b[i];

	}

	for (int i=1;i<=n;++i)

	{

		cnt=0;

		for (int j=0;j<=8;++j)

			if (f(a[i],j)+a[i]>9)

				cnt++;

		cnt*=(b[i]/9);

		for (int j=0;j<=b[i]%9-1;++j)

			if (f(a[i],j)+a[i]>9)

				cnt++;

		if (f(a[i],0)+a[i]>9)

			cnt--;

		ans+=cnt;

	}

	for (int i=1;i<=n;++i)

		a[i]=f(a[i],b[i]);

	for (int i=1;i<=n;++i)

		{

			sum+=a[i];

			if (sum>9)

			{

				sum-=9;

				ans++;

			}

		}

	cout<<ans-1<<endl;

	return 0;

}