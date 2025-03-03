#include<stdio.h>

#include"stdc++.h"

using namespace std;

int main()

{

    int n,m,a[100004]= {0},ans[100002]= {0};

    cin>>n;

    int sum=0;

    for(int i=1; i<=n; i++)

    {

        cin>>a[i];

        sum+=abs(a[i]-a[i-1]);

    }

    sum+=abs(a[n]-0);

    for(int i=1; i<=n; i++)

    {

        int tp=sum;

        if(a[i]>a[i-1]&&a[i]>a[i+1])

        {

            tp=sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]);

        }

        if(a[i]<a[i-1]&&a[i]<a[i+1])

        {

            tp=sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]);

        }

        cout<<tp<<endl;

    }

}
