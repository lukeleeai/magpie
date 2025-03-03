#include"stdc++.h"

#define ll long long

using namespace std;

const ll inf=1e18;

ll a[1010],t[1010],ans1,ans2,ans,l,r,mid;

int n;

int main()

{

	ios::sync_with_stdio(0);

	cin>>n;

	for(int i=1;i<=n;i++)

		cin>>t[i]>>a[i];

	ans1=t[1],ans2=a[1];

	for(int i=2;i<=n;i++)

	{

		if(ans1*a[i]==ans2*t[i])continue;

		else 

		{

			l=1;r=inf/max(a[i],t[i])+1;

			ans=r;

			while(l<=r)

			{

				mid=(l+r)>>1;

				if(mid*t[i]>=ans1&&mid*a[i]>=ans2)ans=mid,r=mid-1;

				else l=mid+1;

			}

			ans1=ans*t[i],ans2=ans*a[i];

		}

	}

	cout<<ans1+ans2<<endl;	

}