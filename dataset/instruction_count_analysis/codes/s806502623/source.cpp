#include"stdc++.h"

using namespace std;

typedef long long l;

l o=0,ans=1;

bool ok=0,w[5000005];

int main()

{

	l n,k;

	cin>>n>>k;

	if(n==1)

	{

		cout<<k<<endl;

		return 0;

	}

	for(int i=2;ok==0;i++)

	{

		if(i*i>k)

			break;

		if(w[i]==1)

			continue;

		o=1;

		for(int c=0;c<n;c++)

		{

			o=o*i;

			if(o>k)

			{

				ok=1;

				break;

			}

		}

		if(k%o==0)

			ans=i;

		else

			for(l d=i;d<5000005;d+=i)

				w[d]=1;

	}

	cout<<ans<<endl;

	return 0;

}