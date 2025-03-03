#include "stdc++.h"

using namespace std;

#define flash ios_base::sync_with_stdio(0); cin.tie(0)

int main()

{



    flash;

    long long n,k,cnt1=0,cnt2=0, ans=0,y;

    cin>>n>>k;



    for(int i=1; i<=n; i++)

    {

        if(i % k == 0)

            cnt1++;

    }



    ans = cnt1*cnt1*cnt1;



    if(k % 2 == 0)

    {

        for(int i=1; i<=n; i++)

        {



            if(i %k == k/2 )

                cnt2++;

        }

    }



    ans += cnt2*cnt2*cnt2;





    cout<<ans<<endl;

    return 0;

}
