#include "stdc++.h"

using namespace std;

const int N = 1e5+10;

typedef long long ll;

ll dis[N],a,b,n,low;

int main()

{

	cin>>n>>a>>b;

	for(int i=1;i<=n;i++)

		scanf("%lld",&dis[i]);

	for(int i=2;i<=n;i++)

		low=low+min((dis[i]-dis[i-1])*a,b);

	cout<<low<<"\n";

}