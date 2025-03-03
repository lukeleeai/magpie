#include"stdc++.h"

using namespace std;

int main()

{

	int ans=0;

	int l,r;

	int n;

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		scanf("%d%d",&l,&r);

		ans+=r-l+1;

	}

	cout<<ans<<endl;

	return 0;

}