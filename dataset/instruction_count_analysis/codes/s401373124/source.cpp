#include"stdc++.h"

using namespace std;

int n,arr[1000005],p[1000005],d;

int main()

{

	cin>>n;

	for(int i=1;i<=n;i++) cin>>arr[i];

	d=arr[1];

	for(int i=2;i<=n;i++) d=__gcd(d,arr[i]);

	if(d!=1) 

	{

		cout<<"not coprime"<<endl;

		return 0;

	}

	for(int i=1;i<=n;i++)

	{

		int k=arr[i];

		for(int j=1;j<=sqrt(k);j++)

		{

			if(k%j==0) 

			{

				if(j!=1&&p[j]==1||p[k/j]==1) 

				{

					cout<<"setwise coprime"<<endl;

					return 0;

				}

				p[j]++,p[k/j]++;

			}

		}

	}

	cout<<"pairwise coprime"<<endl;

}