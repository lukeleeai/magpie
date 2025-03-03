#include<iostream>

#include<algorithm>

#include<math.h>

#include<map>

using namespace std;

map<int,int>mp;

int main()

{

	int a,b,f=0;

	double x,y;

	cin>>a>>b;

	x=a/0.08;y=(a+1)/0.08;

	for(int i=ceil(x);i<y;i++)mp[i]++;

	x=b/0.1;y=(b+1)/0.1;

	for(int i=ceil(x);i<y;i++)

	{

		mp[i]++;

		if(mp[i]>1)

		{

			cout<<i<<endl;

			f=1;

			break;

		}

	}

	if(f==0)cout<<"-1"<<endl;

	return 0;

}