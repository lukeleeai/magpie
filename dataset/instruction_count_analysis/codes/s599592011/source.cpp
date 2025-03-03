#include<iostream>

using namespace std;

int main()

{

	int a[3][3];

	for(int i=0;i<3;i++)

	{

		for(int j=0;j<3;j++)

		{

			cin>>a[i][j];

		}

	}

	int t,b;

	cin>>t;

	while(t--)

	{

		cin>>b;

		for(int i=0;i<3;i++)

		{

			for(int j=0;j<3;j++)

			{

				if(a[i][j]==b)

				  a[i][j]=0;

			}

		}

	}

	bool flag1=0,flag2=0,flag3=0;

	for(int i=0;i<3;i++)

	{

		for(int j=0;j<3;j++)

		{

			if(a[i][j])

			  break;

			if(j==2&&a[i][j]==0)

			  flag1=1;

		}

	}

	for(int j=0;j<3;j++)

	{

		for(int i=0;i<3;i++)

		{

			if(a[i][j])

			  break;

			if(i==2&&a[i][j]==0)

			  flag2=1;

		}

	}

	for(int i=0;i<3;i++)

	{

		if(a[i][i])

		  break;

		if(i==2&&a[i][i]==0)

		  flag3=1;

	}

	for(int i=0;i<3;i++)

	{

		if(a[i][2-i])

		  break;

		if(i==2&&a[i][2-i]==0)

		  flag3=1;

	}

	if(flag1||flag2||flag3)

	  cout<<"Yes"<<endl;

	else

	  cout<<"No"<<endl;

 } 