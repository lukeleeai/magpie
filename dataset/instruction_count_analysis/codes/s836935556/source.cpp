#include"stdc++.h"

using namespace std;

using ll=long long;



int main()

{

    int $=1;

    //cin>>$;

    while($--)

    {

        ll x,k,d;

        cin>>x>>k>>d;

        x=abs(x);

        ll t=x/d;

        ll a=x%d;

        if(k<=t)

        {

            a=x-k*d;

        }

        else{

            k-=t;

            if(k%2==1)

            {

                a-=d;

                a=abs(a);

            }

        }

        cout<<a<<endl;

    }

}





/*

8888888888888888888888888888

    Md. Masud Mazumder

    University of Chittagong

    Department of CSE

8888888888888888888888888888

*/
