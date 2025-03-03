#include "stdc++.h"

/**

AHMED;HASSAN;SAEED

*/

using namespace std;



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    long long a,b,c,x,y;

    cin>>a>>b>>c>>x>>y;

    long long mn=min(x,y);

    long long ans1=0;

    long long ans2=0;

    if(x*a+y*b>=mn*2*c){

        ans1+=mn*c*2;

        if(x>y){

            long long sn=x-y;

            ans1+=min(sn*a,sn*2*c);

        }

        else{

            long long sn=y-x;

            ans1+=min(sn*b,sn*2*c);

        }

    }

    ans2+=x*a+y*b;

    if(ans1!=0)

    cout << min(ans1,ans2) << endl;

    else

    cout << ans2 << endl;

    return 0;

}
