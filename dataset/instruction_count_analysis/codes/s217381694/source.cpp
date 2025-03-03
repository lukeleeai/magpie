#include"stdc++.h"

using namespace std;

int main()

{

    int a,b,c,d,x,y,z;

    cin>>a>>b>>c>>d;

    if(a>b)

    {

        x=a-b;

    }

    else

    {

        x=b-a;

    }

    if(b>c)

    {

        y=b-c;

    }

    else

    {

        y=c-b;

    }

    if(c>a)

    {

        z=c-a;

    }

    else

    {

        z=a-c;

    }

    if( (x<=d && y<=d)|| z<=d)

    {

        cout<<"Yes"<<endl;

    }

    else

    {

        cout<<"No"<<endl;

    }





    return 0;

}
