#include <assert.h>

#include <limits.h>

#include <algorithm>

#include <bitset>

#include <cctype>

#include <cmath>

#include <complex>

#include <deque>

#include <functional>

#include <iomanip>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <unordered_map>

#include <vector>

 

using ll = long long;

using P = std::pair<long double, ll>;

 

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)

#define all(i) i.begin(), i.end()

#define debug(i) std::cerr << "debug " << #i <<" "<<i<< std::endl

 

template <typename T1, typename T2>

std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {

  return os << pa.first << " " << pa.second;

}

 

template <typename T>

std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {

  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");

  return os;

}

 

template<typename T1,typename T2>

inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}

 

template<typename T1,typename T2>

inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

 

// const ll MOD = 998244353;

const ll MOD = 1e9 + 7;





 

int main() {

  std::cin.tie(0);

  std::ios::sync_with_stdio(false);



  ll n,m;

  std::cin>>n>>m;



  std::vector<std::vector<ll>> graph(3*n);



  rep(i,0,m){

    ll u,v;

    std::cin>>u>>v;

    u--;v--;



    rep(j,0,3)graph[u+n*j].push_back((v+n*((j+1)%3)));

  }



  std::vector<bool> used(3*n,false);



  ll s,t;

  std::cin>>s>>t;



  s--;t--;



  std::queue<P> que;



  used[s]=true;

  que.push({s,0});



  while(!que.empty()){

    P e=que.front();que.pop();



    if(e.first==t){

      std::cout<<e.second/3;

      return 0;

    }



    for(ll next:graph[e.first]){

      if(!used[next]){

        used[next]=true;

        que.push({next,e.second+1});

      }

    }

  }



  std::cout<<-1;



  return 0;

}






