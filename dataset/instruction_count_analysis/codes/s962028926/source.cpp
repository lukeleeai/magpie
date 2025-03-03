#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int gcd(int a,int b){

    if(b==0) return a;

    return gcd(b,a%b);

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