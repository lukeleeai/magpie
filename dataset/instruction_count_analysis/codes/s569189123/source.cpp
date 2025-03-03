#include "stdc++.h"

#define INF 1e9

using namespace std;



int fir;



bool solve(long long n,long long m){//nのm分割

    if(n%m!=0 && m%2==1)return false;

    if(m%2==0 && (2*n)%m!=0)return false;

    if((m%2)==1){

        if(((n/m)-((m-1)/2))>=1){

            fir=n/m-(m-1)/2;

            return true;

        }

        else{

            return false;

        }

    }

    else{

        if(((2*n)/m)%2==1){

            fir=(2*n/m-m+1)/2;

            return true;

        }

        else return false;

    }

}



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0);



    while(1){

        int a;

        cin>>a;

        if(a==0)break;

        fir=a;

        int ans=1;

        for(long long i=1;i*i/2<=a;i++){

            if(solve(a,i)){

                    ans=i;

            }

        }

        cout<<fir<<" "<<ans<<endl;

    }

}
