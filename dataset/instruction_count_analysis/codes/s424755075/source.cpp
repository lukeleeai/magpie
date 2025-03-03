#include"stdc++.h"

using namespace std;

long long n,k,q;

long long a[200005],cnt[200005];

int main()

{

    scanf("%lld%lld%lld",&n,&k,&q);	

    for(int i=1;i<=q;++i)

        scanf("%lld",&a[i]),cnt[a[i]] ++;

    for(int i=1;i<=n;++i)

    {

    	if(k-(q-cnt[i]) <= 0) printf("No\n");

    	else printf("Yes\n");

	}

	return 0;

}