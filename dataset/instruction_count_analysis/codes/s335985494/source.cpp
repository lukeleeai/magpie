#include"stdc++.h"

#define ll long long

using namespace std;

int main()

{

	int n;

	cin>>n;

	vector<int>v(n);

	for(int i=0;i<n;i++)

	{

		cin>>v[i];

	}

	sort(v.rbegin(),v.rend());

	int sum=0;

	for(int i=1;i<n;i++)

	{

		sum=sum+v[i];

	}

	if(sum>v[0])

	{

		cout<<"Yes"<<endl;

	}

	else

	{

		cout<<"No"<<endl;

	}

	return 0;

}