#include "stdc++.h"

#define repd(i,a,b) for (int i=(a);i<(b);i++)

#define rep(i,n) repd(i,0,n)

#define int long long

typedef long long ll;

using namespace std;

const int MOD = 1000000007;

const int INF = 1010000000;

const double EPS = 1e-10;

const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 



vector<int> init(int size){

  vector<int> par(size,-1);

  return par;

}



int root(int x, vector<int>& par){

  if(par[x] < 0){

    return x;

  }else{

    return par[x] = root(par[x],par);

  }

}



bool same(int x, int y, vector<int>& par){

  return root(x, par) == root(y, par);

}



void unite(int x, int y, vector<int>& par){

  x = root(x, par), y = root(y, par);

  if(same(x,y, par))return;

  par[x] += par[y];

  par[y] = x;

}



int size(int x, vector<int>& par){

  return -par[root(x, par)];

}



int pow(int x, int n){

  if(n == 0)return 1;

  if(n % 2 == 0)return pow(x * x % MOD, n/2);

  else return x * pow(x, n-1) % MOD;

}



signed main(){

  int x,y,z,k;cin>>x>>y>>z>>k;

  int a[1100], b[1100], c[1100];rep(i,x)cin>>a[i];rep(i,y)cin>>b[i];rep(i,z)cin>>c[i];

  sort(a,a+x,greater<int>());sort(b,b+y,greater<int>());sort(c,c+z,greater<int>());

  vector<int> v;

  rep(i,x){

    rep(j,y){

      rep(l,z){

        if((i+1)*(j+1)*(l+1) > k)break;

        v.push_back(a[i]+b[j]+c[l]);

      }

    }

  }

  sort(v.begin(), v.end(), greater<int>());

  rep(i,k)cout << v[i] << endl;

}
