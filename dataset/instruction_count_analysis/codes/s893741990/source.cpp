#include"stdc++.h"

#define ll long long int

#define sz  200010

using namespace std;





string ss[sz];



int main()

{



    string a,b;

    ll x,y;



    cin>>a>>b;

    x=a.length();

    y=b.length();





    if(x>y)

        cout<<"GREATER"<<endl;

    else if(x<y)

        cout<<"LESS"<<endl;

    else

    {





        for(ll i=0; i<x; i++)

        {

            if(a[i]>b[i])

            {

                cout<<"GREATER"<<endl;

                return 0;

            }

            else if(a[i]<b[i])

            {

                cout<<"LESS"<<endl;

                return 0;

            }

        }



        cout<<"EQUAL"<<endl;

    }



    return 0;

}


