#include "stdc++.h"

#define rep(i,n) for(int i=0;i<n;i++)

#define all(x) (x).begin(),(x).end()

using namespace std;

const int INF=1145141919,MOD=1e9+7;

const long long LINF=8931145141919364364,LMOD=998244353;

inline long long mod(long long n,long long m){return(n%m+m)%m;}

// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};



// unsigned long long modpow(long long a,long long n){

//     long long x=1;

//     while(n>0){

//         //nの2進数表記の右端が1

//         if(n&1){

//             x=x*a;

//         }

//         a=a*a;

//         n>>=1; //nを右に1bitずらす

//     }

//     return x;

// }

int main(){

    long long n,p; cin>>n>>p;

    if(n==1){

        cout<<p<<endl;

        return 0;

    }

    long long MAX=1;

    for(long long i=2;;i++){

        if(pow(i,n)>1e13) break;

        MAX=i+1;

    }

    long long ans=1;

    for(long long i=2;i<=MAX;i++){

        long long tmp=pow(i,n);

        if(p%tmp==0){

            ans=i;

        }else if(p<=tmp){

            break;

        }

    }

    cout<<ans<<endl;

    return 0;

}
