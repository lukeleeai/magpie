#include<cstdio>

#include<cstring>

#include<iostream> 

#include<cmath>

#include<algorithm>

#include<stdlib.h>

using namespace std;



int main()

{

	string ans;

	string ppp;

	int n;

	cin>>n;

	cin>>ppp;

	

	if(ppp.length()>n)

	{

		for(int i=0;i<n;i++)

		{

			ans=ans+ppp[i];

		}

		ans.append(3,'.');

	}

	else

	{

		ans.assign(ppp);

	}

	cout<<ans<<endl;

return 0;

 }