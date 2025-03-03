#include"stdc++.h"



using namespace std;





int main()

{



   short a,b,c;



    while(cin>>a>>b>>c)

    {



      short n1,n2,n3;

      n1=a+b;

      n2=a+c;

      n3=b+c;



      if(n1<n2)

      {

          if(n1<n3)

          {

              cout<<n1<<endl;



          }

            else

                cout<<n3<<endl;

      }



      else

      {

          if(n2<n3)

          {

              cout<<n2<<endl;

          }

          else

            cout<<n3<<endl;

      }



    }

















    return 0;



}
