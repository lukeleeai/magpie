#include"stdc++.h"

using namespace std;

using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}

template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}





template<typename F>

struct FixPoint : F{

  FixPoint(F&& f):F(forward<F>(f)){}

  template<typename... Args>

  decltype(auto) operator()(Args&&... args) const{

    return F::operator()(*this,forward<Args>(args)...);

  }

};

template<typename F>

inline decltype(auto) MFP(F&& f){

  return FixPoint<F>{forward<F>(f)};

}



//INSERT ABOVE HERE

signed main(){

  int n;

  cin>>n;



  vector< vector<int> > G(n);

  for(int i=1;i<n;i++){

    int p;

    cin>>p;

    p--;

    G[p].emplace_back(i);

  }



  vector<int> dp(n);

  MFP([&](auto dfs,int v)->void{

        if(G[v].empty()){

          dp[v]=0;

          return;

        }

        vector<int> us;

        for(int u:G[v]){

          dfs(u);

          us.emplace_back(dp[u]);

        }

        sort(us.rbegin(),us.rend());

        int &res=dp[v];

        res=us[0]+1;

        for(int i=0;i<(int)us.size();i++)

          chmax(res,us[i]+i+1);

      })(0);



  cout<<dp[0]<<endl;

  return 0;

}
