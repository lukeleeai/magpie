#include <iostream>



using namespace std;







int main()

{

    int a,b,t; int r=0;

    cin>>a>>b>>t; int a1=a;

    while(a<=t)

    {

        r+=b;

        a=a+a1;

    }

    cout<<r;

    return 0;

}
