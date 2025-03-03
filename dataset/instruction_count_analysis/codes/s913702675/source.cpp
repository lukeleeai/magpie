#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;



ll gcd(ll a,ll b)

{



    if(b==0)

        return a;

    else

        return gcd(b,a%b);

}



ll lcm(ll a,ll b)

{

    return (a/(gcd(a,b)))*b;



}



int main()

{

    ll t=1;





    while(t--)

    {

        ll a,b,c,d;

        //cout<<lcm(3,4)<<endl;

        cin>>a>>b>>c>>d;

        ll tot=b-a+1;

        ll a1=(a-1)/c+(a-1)/d-((a-1)/lcm(c,d));

        ll b1=b/c+b/d-(b/lcm(c,d));

        //ans= tot-ans;

        //cout<<a1<<" "<<b1<<" "<<tot<<endl;

        cout<<tot-(b1-a1)<<endl;



    }









}
