#include"stdc++.h"

#define N 1005

using namespace std;

int n,m,sum,a[N];

int main(){

    cin>>n;

    for(int i=1;i<=n;i++){

        cin>>a[i];

        sum+=a[i];

    }

    cin>>m;

    while(m--){

        int p,x;

        cin>>p>>x;

        cout<<sum-a[p]+x<<endl;

    }

    return 0;

}