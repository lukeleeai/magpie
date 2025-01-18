#include"stdc++.h"

using namespace std;

int main()

{

    int n,k;

    cin>>n>>k;

    int a[n],cal[n];

    for(int i=0;i<n;i++){cal[i]=1e9+7;cin>>a[i];}

    cal[0]=0;

    for(int i=1;i<n;i++)

    {

        for(int j=i-1;j+k>=i && j>=0;j--){

            cal[i]=min(abs(a[i]-a[j])+cal[j],cal[i]);

        }

    }

    cout<<cal[n-1]<<endl;

}


