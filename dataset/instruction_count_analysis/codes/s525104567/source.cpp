#include "stdc++.h"

using namespace std;

const int mod=1e9+7;

int main(){

    int n,m;

    cin>>n>>m;

    long long p;

    if(abs(n-m)>1) cout<<0<<endl;

    else{

        long long  sum=1,cnt=1;

        for(int i=1;i<=n;i++) {

                sum*=i;

                sum%=mod;

        }

        for(int i=1;i<=m;i++) {

                cnt*=i;

                cnt%=mod;

        }

        p=cnt*sum%mod;

        if(m==n) p*=2;

        p%=mod;

        cout<<p<<endl;

    }

    return 0;

}
