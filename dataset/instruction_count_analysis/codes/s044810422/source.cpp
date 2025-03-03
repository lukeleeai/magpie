#pragma GCC optimize(2)

#pragma GCC optimize(3)

#include"stdc++.h"

using namespace std;

int n,m,a[500050],k,b[500050],ans,ok[2];

int check(int x)

{

	ok[0]=ok[1]=1000000;

	for(int i=1;i<=k;i++)

	b[i]=(a[i]>=x);

	b[0]=b[k+1]=10;

	for(int i=1;i<=k;i++)

	{

		if(b[i]==b[i-1]||b[i]==b[i+1])

		{

			ok[b[i]]=min(ok[b[i]],abs(i-n));

		}

	}

	//cout<<x<<" "<<ok[0]<<" "<<ok[1]<<endl;

	if(ok[1]==ok[0]) return b[1];

	return ok[1]<ok[0];

}

int main()

{

	cin>>n;

	k=2*n-1;

	for(int i=1;i<=k;i++)

	{

		scanf("%d",&a[i]);

	}

	int l=1,r=k;

	while(l<=r)

	{

		int mid=(l+r)/2;

		if(check(mid)) ans=mid,l=mid+1;

		else r=mid-1;

	}

	cout<<ans;

}