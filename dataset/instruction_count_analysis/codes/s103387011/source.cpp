#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

int main()

{

    int a[220000];

    int n;

    cin>>n;

    for(int i=0;i<n;i++)

    {

        cin>>a[i];

    }

     int maxa=-9999999999;

     int maxq=a[0];

     for(int i=1;i<n;i++)

     {



        maxa=max(maxa,a[i]-maxq);

        maxq=min(maxq,a[i]);

     }

     cout<<maxa<<endl;

     return 0;

}