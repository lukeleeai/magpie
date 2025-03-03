#include <iostream>

#include <cmath>

using namespace  std;



int main()

{

    int x,y,z;

    while(cin>>x>>y>>z)

    {

        if(abs(y-x)>=abs(z-x))

        {

            cout<<"B"<<endl;

        }

        else cout<<"A"<<endl;

    }

}
