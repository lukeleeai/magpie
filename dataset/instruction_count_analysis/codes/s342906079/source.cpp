#include<iostream>

#include<cstdio>

#include<cstring>

#include<iomanip>

#include<cmath>

using namespace std;

int main()

{   int n,m,i,j,s=0;

    char a[105][105];

    cin>>n>>m;

    for(i=1;i<=n;i++)

      for(j=1;j<=m;j++)cin>>a[i][j];

    for(i=1;i<=n;i++)

    {  for(j=1;j<=m;j++)

      {  if(a[i][j]=='#')cout<<a[i][j];

           else {  if(a[i-1][j-1]=='#')s++;

                   if(a[i-1][j]=='#')s++;

                   if(a[i-1][j+1]=='#')s++;

                   if(a[i][j+1]=='#')s++;

                   if(a[i+1][j+1]=='#')s++;

                   if(a[i+1][j]=='#')s++;

                   if(a[i+1][j-1]=='#')s++;

                   if(a[i][j-1]=='#')s++;

                   cout<<s;

                   s=0;

                }

      }

      cout<<endl;

    }

    return 0;

}	