#include"stdc++.h"

using namespace std;

int main()

{

	int n;

	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)

	cin>>a[i];

	int ans=0;

	for(int i=0;i<n;i++)

	{

		if(a[i]==ans+1)

		{

			ans++;

		}

	}

	if(ans==0)

	cout<<-1<<endl;

	else

	cout<<n-ans<<endl;

}