#include<iostream>

#include<cstring>

using namespace std;

const long long M=1e9+7;

int main()

{

	int n;

	while(cin>>n)

	{

		int flag=1;

		int a[100005],b[100005];

		memset(b,0,sizeof(b));

		for(int i=0;i<n;i++)

		{

			cin>>a[i];

		}

		if(n%2==1)

		{	

		    for(int i=0;i<n;i++)

			{

				b[a[i]]++;

			}

			for(int i=2;i<n;i=i+2)

			{

				if(b[0]!=1)

				{

				    flag=0;

				    break;

			    }

				else if(b[i]==2)

				continue;

				else

				{

					flag=0;

					break;

				}

			} 

		}

		if(n%2==0)

		{

			for(int i=0;i<n;i++)

			{

				b[a[i]]++;

			}

			for(int i=1;i<n;i=i+2)

			{

				if(b[i]==2)

				continue;

				else

				{

					flag=0;

					break;

				}

			}

	    }

	    long long sum=1;

		if(flag==1)

		{

			for(int i=0;i<n/2;i++)

			{

				sum*=2;

				sum%=M;

			}

			cout<<sum<<endl;

		}

		else

		cout<<"0"<<endl;

	}

	return 0;

} 