#include "stdc++.h"

#define int long long

using namespace std;



int n,ii=0,now=0;



signed main()

{

	cin>>n;

	while (ii<=80000000)

	{

		ii++;

		now=(now*10+7)%n;

		

		if (now==0)  return cout<<ii<<endl,0;

	}

	cout<<-1<<endl;

	return 0;

}