#include"stdc++.h"

#include<string.h>

using namespace std;

int main()

{

    string a,b,c;

    char x,y,z,w;

    int d,e,f;

    cin>>a>>b>>c;

    d=a.size();

    x=a[d-1];

    y=b[0];

    e=b.size();

    z=b[e-1];

    w=c[0];



    if(x==y && z==w)

    {

        cout<<"YES"<<endl;

    }

    else

    {

        cout<<"NO"<<endl;

    }

}
