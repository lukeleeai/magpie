#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <functional>

#include <cmath>

#include <iomanip>

#include <stack>

#include <queue>

#include <numeric>

#include <map>

#include <unordered_map>

#include <set>

#include <fstream>

#include <chrono>

#include <random>

#include <bitset>

#define rep(i,n) for(int i=0;i<(n);i++)

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define sz(x) ((int)(x).size())

#define pb push_back

using ll = long long;

using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}



int main(){

  //int X; cin >> X;

  int t; cin >> t;

  int output;

  for(int X=1;X<=179;X++){

    double px=0,py=0;

    int ans = 0;

    double deg = X;

    do{

      px += cos(deg*2*acos(-1)/360);

      py += sin(deg*2*acos(-1)/360);

      deg += X;

      ans++;

    }while(abs(px)>0.00001 || abs(py)>0.00001);

    int ans2=0;

    int now=0;

    rep(i,1000){

      now += X;

      ans2++;

      if(now%360==0) break;

    }

    if(ans^ans2) cout << "!";

    if(X==t) output = ans;

  }

  cout << output << endl;

  return 0;

}
