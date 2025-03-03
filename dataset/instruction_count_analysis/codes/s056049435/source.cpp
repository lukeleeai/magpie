#include"stdc++.h"

using namespace std;

typedef long long ll;

const int mod=1e9+7;

#define inf 0x3f3f3f3f

int a[15];



int main()

{

	for(int i=0;i<3;i++)

	cin>>a[i];

	sort(a,a+3);

	int x=a[0],y=a[1],z=a[2];

	int ans=0;

	while(x+2<=y)

	{

		ans++;

		x+=2;

	}

	if(x==y)

	ans+=z-y;

	else

	{

		if(z==y)

		{

			ans+=2;

		}

		else

		{

			ans+=z-y+2;

		}

	 } 

	cout<<ans;

	return 0;

}