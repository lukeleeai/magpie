#include"stdc++.h"

#define ll long long int

#define sz  200010

using namespace std;





string ss[sz];



int main()

{





    string x="";



    ll h,w,i,j,k,p,a,b;



    cin>>h>>w;



    for(i=1; i<=h; i++)cin>>ss[i];



    for(i=1; i<=w+2; i++)x+="#";



    cout<<x<<endl;

    for(i=1; i<=h; i++)

    {

        cout<<"#"<<ss[i]<<"#"<<endl;

    }

    cout<<x<<endl;







    return 0;

}


