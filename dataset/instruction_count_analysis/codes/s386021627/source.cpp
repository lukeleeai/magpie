#include "stdc++.h"

#define int ll

using namespace std;

typedef long long ll;

 

ll n,s,ans=10000000000000ll;

inline bool check(int x)

{

	if(x==1) return 0;

	ll tt=0,ts=n;

	while(ts)

	{

		tt+=ts%x;

		ts/=x;

	}

//	if(x==10) printf("%d\n",tt);

	return tt==s;

}

signed main()

{

	cin >> n >> s;

	if(n==s){printf("%lld\n",n+1); return 0;}

	for(int i=1;i<=sqrt(n);i++)

	{

		if((n-s+i)%i==0&&i*i<n){ if(((n-s+i)/i)) if(n/((n-s+i)/i)==i) ans=min(ans,(n-s+i)/i);}

		if(check(i)) ans=min(ans,(ll)i);	

	}

	if(ans==10000000000000ll) puts("-1");

	else cout << ans << endl;

	return 0;

}