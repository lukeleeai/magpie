#include<iostream>

#include<stdio.h>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<map>

#include<set>

#include<queue>

#define ll long long

using namespace std;

int pos(int n)

{

    if(n<0)

        return 0;

    else

        return n;

}

int main()

{

    int a[100002][2]= {0};

    int n;

    cin>>n;

    ll sum=0;

    for(int i=1; i<=n; i++)

    {

        scanf("%d",&a[i][0]);

 

        sum+=abs(a[i-1][0]-a[i][0]);

    }

    sum+=abs(a[n][0]);

    for(int i=1; i<=n; i++)

    {

 

            cout<<sum-abs(a[i][0]-a[i+1][0])-abs(a[i][0]-a[i-1][0])+abs(a[i-1][0]-a[i+1][0])<<endl;

 

  

    }

}