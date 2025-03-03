#include <iostream>

#include <iomanip>

#include <string>

#include <stack>

#include <vector>

#include <math.h>

#include <stdio.h>

#include <algorithm>

#include <utility>

#include <functional>

#include <map>

#include <set>

#include <queue>

#include <list>

using namespace std;

using pii  = pair<int,int>;

using ll=long long;

using ld=long double;

#define pb push_back

#define mp make_pair

#define rep(i,n) for(ll i=0;i<(n);++i)

#define REP(i,a,b) for(ll i=(a);i<(b);++i)

#define crep(i) for(char i='a';i<='z';++i)

#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});

#define ALL(x) (x).begin(),(x).end()

#define endl '\n'

int ctoi(const char c){

    if('0' <= c && c <= '9') return (c-'0');

    return -1;

}

long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}

long long lcm(long long a, long long b){return a*b/gcd(a,b);}

constexpr ll MOD=1000000007;

constexpr ld EPS=10e-8;

template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}

template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}

template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}

template<class T> ostream& operator<<(ostream& os, vector<T>& v){

    for(auto i=begin(v); i != end(v); ++i){

        if(i !=begin(v)) os << ' ';

        os << *i;

    }

    return os;

}



ll dp[3007][3007];



int main(){

  string S,T;

  cin >> S >> T;

  rep(i,3005){

    dp[i][0]=0;

    dp[0][i]=0;

  }

  rep(i,S.size()){

    rep(j,T.size()){

      if(S[i]==T[j]){

        dp[i+1][j+1]=dp[i][j]+1;

      }

      else{

        dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);

      }

    }

  }

  string s;

  ll i=S.size(),j=T.size();

  while(i>0||j>0){

    if(i>0&&j>0&&dp[i][j]>dp[i-1][j-1]&&dp[i][j]>dp[i-1][j]&&dp[i][j]>dp[i][j-1]){

      s=S[i-1]+s;

      i--;j--;

    }

    else if(i>0&&dp[i][j]==dp[i-1][j]){

      i--;

    }

    else{

      j--;

    }

  }

  cout << s << endl;

}