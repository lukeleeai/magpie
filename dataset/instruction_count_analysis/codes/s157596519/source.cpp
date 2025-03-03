#include<iostream>

using namespace std;

int main(){

   double w,a,b;

   cin>>w>>a>>b;

   if(w+a< b)

      cout<<b-(a+w);

     else if(a> b+w)

       cout<<a-(b+w);

       else 

           cout<<"0";

       



	 	return 0;

}