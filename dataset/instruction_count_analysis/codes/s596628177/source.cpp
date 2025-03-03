#include<iostream>

using namespace std;

const int maxi=8000;

int main()

{

     long long k,s,i,j,a[maxi],count,sum;

     while(cin>>k>>s)

     {

         for(i=0;i<=7500;i++)

            a[i]=0;

         count=0;

         for(i=0;i<=k;i++)

         {

             for(j=0;j<=k;j++)

             {

                 a[i+j]++;

             }

         }

         for(i=0;i<=k;i++)

         {

             sum=s-i;

             if(sum<0) continue;

             else count+=a[sum];

         }

         cout<<count<<endl;

     }

     return 0;

}
