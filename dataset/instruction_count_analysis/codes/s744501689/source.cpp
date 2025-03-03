#include"stdc++.h"

using namespace std;

typedef long long ll;

ll m,n;

ll ans;

int main()

{

    scanf("%lld%lld",&m,&n);

    ans=abs((n-2)*(m-2));

    printf("%lld\n",ans);

}