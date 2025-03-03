#include "stdc++.h"

using namespace std;

long long int ar[1000000];

int main()

{

  long long  int x, y,rem,temp,i,j,total,f=0;

   cin >> x >> y;

    temp=x;

    for(i=0;i<1000000;i++)

    ar[i]=-1;

     i=0;

    while(temp>=1)

    {

        rem=temp%y;

        temp=temp/y;

        ar[i]=rem;

        i++;



    }

    for(j=0;j<i;j++)

    {

         total=ar[j]%10;

            f++;

    }

    cout<<f<<endl;

}
