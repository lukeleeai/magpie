#include"stdc++.h"

using namespace std;

typedef long long ll;



int main()

{

    int n;

    scanf("%d",&n);

    ll a, b, pr ,sqq;

    ll ans;

    while(n--)

    {

        scanf("%lld%lld",&a,&b);

        pr=a*b;

        sqq=sqrt(pr);

        //printf("%lld\n",sqq);

        ans=sqq*2;

        if(sqq*sqq==pr){

            if(a==sqq&&b==a){

                ans-=2;

            }

            else{

                ans-=3;

            }

        }

        else{

            if((pr-1)/sqq==sqq){

                ans--;

            }

            ans--;

        }

        printf("%lld\n",ans);

    }

    return 0;

}
