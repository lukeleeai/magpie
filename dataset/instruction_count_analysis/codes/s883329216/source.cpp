#include<cmath>

#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

int main() {

    #ifdef LOACL

    freopen("in.txt","r",stdin);

    freopen("out.txt","w",stdout);

    #endif

    int t;

    scanf("%d",&t);

    while(t--) {

    	ll a,b,ans;

    	scanf("%lld %lld",&a,&b);

    	if(a>b)swap(a,b);

    	if(a==b) {

    		ans=2*(a-1);

		} else if(a+1==b) {

			ans=2*(a-1);

		} else {

			ll c=sqrt(a*b);

			if(c*c==a*b)c--;

			if(c*(c+1)>=a*b) {

				ans=2*c-2;

			} else {

				ans=2*c-1;

			}

		}

		printf("%lld\n",ans);

	}

    return 0;

}