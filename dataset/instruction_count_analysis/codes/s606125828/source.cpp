#include <iostream>



using namespace std;

int main()

{

    float n,t,a,h[1000000]={},num=0,z=999999999,x=0;

    cin>>n>>t>>a;

    for (int i=1; i<=n; i++)

    {

        cin>>h[i];

    }

        num=(t-a)/0.006;

    

    for (int i=1; i<=n; i++)

       {

           if (num>=h[i])

           {

               if (num-h[i]<z)

               {

                   x=i;

                   z=num-h[i];

               }

           }

           if (num<h[i])

           {

               if (h[i]-num<z)

               {

                   x=i;

                   z=h[i]-num;

               }

           }

       }

    cout<<x;

    return 0;

}