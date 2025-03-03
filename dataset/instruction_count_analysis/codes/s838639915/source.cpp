#include<iostream>

#include<algorithm>

#include<cmath>

#include<cstring>

using namespace std;

int map[100005];

int main()

{

	int n,maxn=0,mine=666666,sum=0;

	memset(map,0,sizeof(map));

	cin>>n;

	while(n--)

	{

		int a,b;

		cin>>a>>b;

		maxn=max(a,maxn);

		maxn=max(b,maxn);

		mine=min(a,mine);

		mine=min(a,mine);

		for(int i=a; i<=b; i++)

		{

			if(map[i])

				continue;

			else

				map[i]=1;

		}

	}

	for(int i=mine; i<=maxn; i++)

		if(map[i])

			sum++;

	cout<<sum<<endl;

	return 0;

}