#include "stdc++.h"

using namespace std;

const int MAXN = 20;

struct number

{

	int f,s;

}a[1<<MAXN];

int n;

int main()

{

	scanf("%d", &n);

	for(int i=0;i<1<<n;i++)

	{	

		int x;

		scanf("%d", &x);

		a[i].f=x; 

	}

	for(int j=0;j<n;j++)

		for(int i=0;i<1<<n;i++)

			if(i>>j & 1) 

			{

				int x=i^(1<<j); 

				number ans;

				ans.f=max(a[i].f,a[x].f); 

				if(a[i].f>a[x].f) 

					ans.s=max(a[i].s,a[x].f); 

				else

					ans.s=max(a[i].f,a[x].s);

				a[i]=ans;

			}

	int ans=0;

	for(int i=1;i<1<<n;i++)

	{

		ans=max(ans,a[i].f+a[i].s); 

		cout<<ans<<endl;

	}

	cout<<endl;

	return 0;

}