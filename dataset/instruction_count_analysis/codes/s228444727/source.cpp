#include"stdc++.h"

using namespace std;

int n;

int a[100005];

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;++i)

	    scanf("%d",&a[i]);

	sort(a+1,a+1+n);

	int l=1,r=0;

	int ans=0;

//	for(int i=1;i<=n;++i) 

//	   cout<<a[i]<<" ";

//	  cout<<endl; 

	while(r!=n)

	{

		++r;

		if(a[r] != a[l] || r==n)

		{

			int t=r-l;

			//cout<<r<<" "<<l<<" "<<t<<" "<<a[l]<<endl;

			if(r==n) ++t;

			if(t >= a[l])  ans+=t-a[l];

			else ans+=t;

			//cout<<ans<<endl;

			l=r;

		}

	}   

	printf("%d\n",ans);

	return 0;

}