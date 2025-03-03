#include"stdc++.h"

using namespace std;

const int N=1e5+5;

int n,c,k,a[N],ans,sum,ji;

int main()

{

	cin>>n>>c>>k;

	for(int i=0;i<n;i++)cin>>a[i];

	sort(a,a+n);

	ji=a[0];

	sum=1;

	for(int i=1;i<n;i++)

	{

		if(k<a[i]-ji||sum==c)

			ans++,sum=1,ji=a[i];

		else

			sum++;

	}

	if(sum)ans++;

	cout<<ans<<endl;

}