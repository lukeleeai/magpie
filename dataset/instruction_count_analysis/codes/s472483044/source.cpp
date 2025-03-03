#include"stdc++.h"

using namespace std;

#define faster_io ios_base::sync_with_stdio(0);

#define ll long long



int main()

{

    faster_io;



    int n,i,j,k,temp=0,sum=0,sum1;

    cin>>n;

    int a[n+5],b[n+5];

    a[0]=0;

    a[n+1]=0;

    for(i=1;i<=n;i++){

        cin>>a[i];

        b[i]=abs(temp-a[i]);

        temp=a[i];

        sum+=b[i];

    }



    b[i]=abs(a[n]-0);

    sum+=b[i];

    sum1=sum;



    for(i=0,j=1;j<=n;i++,j++){

        sum-=(b[j]+b[j+1]);

        sum+=(abs(a[j-1]-a[j+1]));

        cout<<sum<<endl;

        sum=sum1;

    }



    return 0;

}




