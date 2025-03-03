#include<iostream>

#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)

{

	if(a.second<b.second)

	 return true;

	else

	 return false;

}

int main()

{

	int n;

	pair<int,int> p[100100];

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		int t;

		cin>>t;

		p[i].first=i;

		p[i].second=t;

	} 

	sort(p+1,p+n+1,cmp);

	for(int i=1;i<=n;i++)

	 cout<<p[i].first<<" ";

	return 0;

	

} 