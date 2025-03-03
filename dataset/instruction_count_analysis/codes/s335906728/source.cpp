#include "stdc++.h"

using namespace std;



int main()

{

	int a,b,c,x,y;

	cin>>a>>b>>c>>x>>y;

	

	vector<long long> dp((int)1e5+1);

	for(int i=0;i<=(int)1e5;i++)

	{

		dp[i] = max(0,x-i)*a + max(0,y-i)*b + i*2*c*1LL;

	}

	cout<<*min_element(dp.begin(),dp.end());

	return 0;

}