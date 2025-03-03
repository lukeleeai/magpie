#include "stdc++.h"

#define rep(i,n) for(int i=0;i<n;i++)

#define all(x) (x).begin(),(x).end()

using namespace std;

const int INF=1145141919,MOD=1e9+7;

const long long LINF=8931145141919364364,LMOD=998244353;

inline long long mod(long long n,long long m){return(n%m+m)%m;}

// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};



map<long long,int> mp;

vector<long long> prime_factorization(long long a){

    vector<long long> v;

    if(a==1) v.push_back(1);

    long long i=2,n=a;

    while(n>1){

        if(a<i*i){

            v.push_back(i);

            mp[n]++;

            return v;

        }

        if(n%i==0){

            n/=i;

            v.push_back(i);

            mp[i]++;

        }else{

            i++;

        }

    }

    return v;

}

int main(){

    long long n,p; cin>>n>>p;

    if(n==1){

        cout<<p<<endl;

        return 0;

    }

    vector<long long> v=prime_factorization(p);

    long long ans=1;

    for(auto i:mp){

        ans*=pow(i.first,i.second/n);

    }

    cout<<ans<<endl;

    return 0;

}
