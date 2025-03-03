//#define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

using ll = long long;

#define pp pair<int,int>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

#define ld long double

#define al(a) (a).begin(),(a).end()

#define mk make_pair

#define check cout<<"?"<<endl;



ll MOD=1000000007;

ll mod=998244353;

int inf=1000001000;

ll INF=1e18+5;



int main(){

    int n,m,ans=0; cin>>n>>m;

    set<pp> path;

    rep(i,m){

        int a,b; cin>>a>>b;

        a--; b--;

        path.insert(mk(a,b));

        path.insert(mk(b,a));

    }

    vector<int> v(n,0);

    rep(i,n) v[i]=i+1;

    do{

        if(v[0]!=1) break;

        int d=1;

        rep(i,n-1){

            if(!(path.count(mk(v[i]-1,v[i+1]-1)))) d=0;

        }

        if(d) ans++;

    }while(next_permutation(al(v)));

    cout<<ans<<endl;

}