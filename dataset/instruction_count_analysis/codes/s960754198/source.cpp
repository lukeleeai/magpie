#include <cassert>

#include <cctype>

#include <cerrno>

#include <cfloat>

#include <ciso646>

#include <climits>

#include <clocale>

#include <cmath>

#include <csetjmp>

#include <csignal>

#include <cstdarg>

#include <cstddef>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>

#include <cwchar>

#include <cwctype>

#include <ccomplex>

#include <cfenv>

#include <cinttypes>

#include <cstdbool>

#include <cstdint>

#include <ctgmath>

#include <algorithm>

#include <bitset>

#include <complex>

#include <deque>

#include <exception>

#include <fstream>

#include <functional>

#include <iomanip>

#include <ios>

#include <iosfwd>

#include <iostream>

#include <istream>

#include <iterator>

#include <limits>

#include <list>

#include <locale>

#include <map>

#include <memory>

#include <new>

#include <numeric>

#include <ostream>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <stdexcept>

#include <streambuf>

#include <string>

#include <typeinfo>

#include <utility>

#include <valarray>

#include <vector>

#include <array>

#include <atomic>

#include <chrono>

#include <codecvt>

#include <condition_variable>

#include <forward_list>

#include <future>

#include <initializer_list>

#include <mutex>

#include <random>

#include <ratio>

#include <regex>

#include <scoped_allocator>

#include <system_error>

#include <thread>

#include <tuple>

#include <typeindex>

#include <type_traits>

#include <unordered_map>

#include <unordered_set>

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

#define all(x) (x).begin(),(x).end()

#pragma GCC optimize("Ofast")

using namespace std;

typedef int64_t ll;

typedef long double ld;

const ll INF=(1LL<<60);

const ld pi=acosl((ld)1);

const ll mod = 1000000007;

const int dx[4]={0,1,0,-1};

const int dy[4]={1,0,-1,0};

const int ddx[8]={1,0,-1,-1,-1,0,1,1};

const int ddy[8]={1,1,1,0,-1,-1,-1,0};



bool solve(){

  ll n,m;cin>>n>>m;

  vector<ll>A[n];

  rep(i,n){

    ll K;cin>>K;

    A[i].resize(K);

    rep(j,K){

      cin>>A[i][j];

      A[i][j]--;

    }

  }

  ll ans=0;

  rep(j,m){

    //食べ物jが好きか

    bool isOK=true;

    rep(i,n){

      bool isLike=false;

      rep(k,A[i].size()){

        if(A[i][k]==j)isLike=true;

      }

      if(!isLike)isOK=false;

    }

    if(isOK)ans++;

  }

  cout<<ans<<endl;return false;

}





signed main(){

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout<<fixed;

	cout<<setprecision(30);

	return solve();

}
