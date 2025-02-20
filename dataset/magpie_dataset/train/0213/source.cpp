#include"stdc++.h"

#define ll long long int

using namespace std;

ll i, j , k , l , n,counter;

 bool ara3[200000];

 void seive()

 {

     for(i= 2; i<=100001; i++)

     {

         ara3[i]  = true;

     }

     ara3[1]  = false;

     for(i=2 ; i<=100001; i++)

     {

         for(j=2;i*j<=100001; j++)

         {

             if(ara3[i]==true)

             {

                 ara3[i*j] = false;

             }

         }

     }

 }

int main(void)

{

    seive();

     while(cin>>n)

     {

         counter = 0;

         for(i=1,j=n; i<=n; i++,j--)

         {

             if(ara3[i]==true && ara3[j]==true)

             {

                 counter++;

             }



         }

         cout<<counter<<endl;

     }

     return 0;



}