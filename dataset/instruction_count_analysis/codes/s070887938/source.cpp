#include"stdc++.h"

using namespace std;

int main()

{

    int a[1001];

    memset(a,0,sizeof(a));

    for(int i=1;i<=999;i++) {

            a[i] =i + a[i-1];



    }

    int c,d;

    cin>>c>>d;



	for (int x = 1; x <= 499500; x++)

    {

        for(int i=2;i<=999;i++)

       {

         if(a[i-1]-x==c && a[i]-x==d)

         {

            cout<<x<<endl;

            return 0;

         }

       }

    }



}
