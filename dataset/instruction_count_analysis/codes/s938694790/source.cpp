#include<iostream>

#include<cmath>

using namespace std;

int main ()

{

    int c=0,d ;

    int a,b;

    cin>>a>>b;

    if (a<b)

    {

        d=a;

        a=b;

        b=d;

    }

    int i;

    for (i=0; i<=a; i++)

    {

        if (abs(a-i) == abs (b-i))

        {

            cout<<i<<endl;

            return 0;

        }

        else c++;

    }



    if (c !=0)

    {

        cout<<"IMPOSSIBLE"<<endl;

    }









    return 0;

}


