#include"stdc++.h"

using namespace std;

int p(int a,int b,int c){

        if(a+b>c&&a+c>b&&b+c>a){

            return 1;

        }

    return 0;

}

    

int main(){

    int n,a[100001];

    cin>>n;

    for(int i=1;i<n+1;i++){

        cin>>a[i];

    }

    int ans=0;

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){

            int it=lower_bound(a+1, a+n+1, a[i]+a[j])-a-2;

            if(it-j+1>0){

                ans+=it-j+1;

            }

        }

    }

    cout<<ans;

    return 0;

}
