#include"stdc++.h"

using namespace std;

int main()

{

	int x,y,z;

	cin>>x>>y>>z;

	int s=0;x-=z;

	while((x-y-z)>=0)

	{

		s++;

		x=x-y-z;

	}

	cout<<s<<endl;

	return 0;

}