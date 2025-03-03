#include<cstdio>

#include<cstdlib>

#include<algorithm>

#include<iostream>

#include<queue>

#include<vector>

#include <bitset>

#include <cmath>

#include <limits>

#include <iostream>

#include<set>

#include<tuple>

using namespace std;

#define INF 11000000000

#define MAX 100000

#define MOD 1000000007

typedef long long ll;

typedef pair<int,int> P;

typedef pair<pair<int,int>,int> p;

typedef pair< pair<int,int>, int> p; 

#define bit(n,k) ((n>>k)&1) /*nのk bit目*/

#define rad_to_deg(rad) (((rad)/2/M_PI)*360)





int main(){

    int N,Q;

    cin>>N>>Q;

    tuple<ll,ll,ll> ob[210000];

    for(int i=0;i<N;i++){

        ll s,t,x;

        cin>>s>>t>>x;

        s-=x;

        t-=x;

        ob[i]=tie(x,s,t);

    }

    sort(ob,ob+N);

    set<P> S;

    for(int i=0;i<Q;i++){

        int d;

        cin>>d;

        S.insert( P(d,i+1) );

    }

    ll ans[210000];

    for(int i=0;i<210000;i++) ans[i]=-1;

    for(int i=0;i<N;i++){

        ll x,l,r;

        tie(x,l,r)=ob[i];

        auto it=S.lower_bound( P(l,-1) );

        while(it!=S.end()){

            if(it->first>=r) break;

            ans[it->second]=x;

            S.erase(it++);

        }

    }

    for(int i=1;i<=Q;i++){

        cout<<ans[i]<<endl;

    }

    

}


