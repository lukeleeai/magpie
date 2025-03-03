#include<cmath>

#include<cstdio>

#include<stdlib.h>

#include<algorithm>

#include<cstring>

#include<iostream>

#include<iomanip>

#include<string>

using namespace std;

int main()

{

	int a,b,cont[10000+50],boom[105][105];

	while(cin>>a>>b)

	{

		memset(cont,0,sizeof(cont));

		memset(boom,0,sizeof(boom));

		int n,i,j,sum=0;

		cin>>n;

		//temp=n;

		for(i=0;i<n;i++)

			cin>>cont[i];

		for(i=0;i<a;i++)

		{

			if(i%2==0)

				for(j=0;j<b;j++)

				{

					boom[i][j]=sum+1;

					cont[sum]--;

					if(cont[sum]==0)sum++;

				}

			else

				for(j=b-1;j>=0;j--)

				{

					boom[i][j]=sum+1;

					cont[sum]--;

					if(cont[sum]==0)sum++;

				}

		}

		for(i=0;i<a;i++)

		{

			for(j=0;j<b-1;j++)

				cout<<boom[i][j]<<" ";

			cout<<boom[i][j]<<endl;

		}

	}

	return 0;

}
