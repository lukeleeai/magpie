

#include<iostream>

#include<stdio.h>

#include<algorithm>

#include<stack>

#include<cstring>

using namespace std;

typedef long long ll;

ll a[1111111];

int main()

{

	ios::sync_with_stdio(false);

	ll n;	cin>>n;

	ll xx=0;

	ll yy=0;

	ll zz=0;

	ll sum=0;

	string ss[111111];

	

	for(ll i=0;i<n;i++)

	{

		string s;	cin>>s;

		if(s[0]=='B'&&s[s.size()-1]=='A')

		{

//			ss[zz][0]='B';

//			ss[zz][1]='A';

			zz++;

		}

		if(s[0]=='B'&&s[s.size()-1]!='A')

			xx++;	

		if(s[0]!='B'&&s[s.size()-1]=='A')

			yy++;

		for(ll j=0;j<s.size()-1;j++)

		{

			if(s[j]=='A'&&s[j+1]=='B')

				sum++;

		}

		

	}

	//cout<<sum;

	int xx1=0;

	int yy1=0;

	if(zz)

	{

		sum=sum+zz-1;

		if(xx)

			yy1=1;

		if(yy)

			xx1=1;	

	}

	xx=xx+xx1;

	yy=yy+yy1;

	sum=sum+min(xx,yy);

	cout<<sum<<endl;

	return 0;

}


