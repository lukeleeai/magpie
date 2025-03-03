#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int gcd(int a,int b){

    int GCD=1;

    rep(i,min(a,b)){

        if(a%(i+1)==0 && b%(i+1)==0) GCD=i+1;

    }

    return GCD;

}

int main(){

    int k;

    cin>>k;

    long long ans=0;

    rep(i,k){

        rep(j,k){

            rep(l,k){

                ans+=gcd((i+1),gcd(j+1,l+1));

            }

        }

    }

    cout<<ans;

}