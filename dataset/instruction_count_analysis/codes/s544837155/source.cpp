#include<iostream>

using namespace std;

int a[3][103];

int main()

{

	int sum=-1;

	

	int n;

	 cin>>n;

	for(int i=1;i<=n;i++)

	  cin>>a[1][i];

	for(int i=1;i<=n;i++)

	  cin>>a[2][i];

	

	

		for(int i=1;i<=n;i++)

		{

			int ans1=0;

			int ans2=0;//记得清零 

			for(int j=1;j<=i;j++)

			{

				ans1=ans1+a[1][j];

			}

			for(int m=i;m<=n;m++)

			{

				ans2=ans2+a[2][m];

			}

			if(sum<(ans1+ans2)) sum=ans1+ans2;

		}

	cout<<sum<<endl;

	return 0;

} 