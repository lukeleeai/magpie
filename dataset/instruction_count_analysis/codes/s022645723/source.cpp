#define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

#define pp pair<int,int>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

#define ll long long

#define ld long double

#define al(a) (a).begin(),(a).end()

#define mk make_pair

ll MOD=1000000007;

ll mod=998244353;

int inf=1000001000;

ll INF=1e18+5;



int main() {

  int n,m,ans=0; cin>>n>>m;

  vector<vector<int>> path(n);

  vector<int> p;

  rep(i,n) p.push_back(i);

  rep(i,m){

    int a,b; cin>>a>>b;

    a--; b--;

    path[a].push_back(b);

    path[b].push_back(a);

  }

    do{

      if(p[0]!=0) break;

      

      int ju=0;

      rep(i,n-1){

        ju=0;

        for(auto q : path[p[i]]) if(q==p[i+1]) ju=1;

        if(ju!=1) break; 

        if(i==n-2) ans++;

      }

    } while(next_permutation(al(p)));

  

  cout<<ans<<endl;

}
