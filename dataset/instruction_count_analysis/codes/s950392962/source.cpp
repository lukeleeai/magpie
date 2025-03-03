#include "stdc++.h"

using namespace std;

int main()

{

    int a,b;

    cin>>a>>b;

    if(a>b)

    {

        if(b==1 && b<a)

        {

            cout<<"Bob"<<endl;

        }

        else

            cout<<"Alice"<<endl;

    }

    else if(a<b)

    {

        if(a==1 && a<b)

        {

            cout<<"Alice"<<endl;

        }

        else

            cout<<"Bob"<<endl;

    }

    else

        cout<<"Draw"<<endl;

}
