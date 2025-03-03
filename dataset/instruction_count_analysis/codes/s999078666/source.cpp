#include"stdc++.h"

using namespace std;



int main(){



  int a,b,c,d,e,f,g,h,i;

  

  cin>>a>>b>>e;





  for(int s=-300;s<=300;s++){



    h=s-(b+e);



    c=s-(a+b);



    i=s-(a+e);



    f=s-(c+i);



    d=s-(e+f);



    g=s-(c+e);



    if(a+b+c==s&&d+e+f==s&&g+h+i==s&&a+d+g==s&&b+e+h==s&&c+f+i==s&&a+e+i==s&&c+e+g==s){



      cout<<a<<' '<<b<<' '<<c<<endl;

      

      cout<<d<<' '<<e<<' '<<f<<endl;

      

      cout<<g<<' '<<h<<' '<<i<<endl;

      

      return 0;

    }

    

  }

  

  return 0;

}
