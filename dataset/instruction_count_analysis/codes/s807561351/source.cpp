#include<iostream>

using namespace std;

int main()

{

          string a;

          cin>>a;

          for(int i=0;i<a.length();i++)

          {

                    if(a[i]!='z')

                    {

                    if(islower(a[i]))

                              a[i]=a[i]+1;}

          }

          cout<<a<<endl;

return 0;

}
