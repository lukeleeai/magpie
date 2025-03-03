#include <iostream>

#include <cstdio>

#include <vector>

#include <complex>

#include <algorithm>

#include <set>

#include <map>

#include <queue>

#include <string>

#include <cstring>

#include <stack>

#include <cmath>

#include <iomanip>

#include <sstream>

#include <cassert>



using namespace std;



typedef long long ll;

typedef ll li;

typedef pair<int,int> PI;

#define EPS (1e-10L)

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define F first

#define S second

#define mp(a,b) make_pair(a,b)

#define pb(a) push_back(a)

#define SZ(a) (int)((a).size())

#define ALL(a) a.begin(),a.end()

#define FOR(it,a) for(__typeof(a.begin())it=a.begin();it!=a.end();++it)

void pkuassert(bool t){t=1/t;};



int dx[]={0,1,0,-1,1,1,-1,-1};

int dy[]={1,0,-1,0,-1,1,1,-1};



int N,M;



map<string,int> s2im;

int s2i(string a){

  if(s2im.count(a))

    return s2im[a];

  int sz=SZ(s2im);

  return s2im[a]=sz;

}



int in[200][200];

int g[200][200];



void solve(){

  rep(i,200)rep(j,200) g[i][j]=in[i][j]=9999+1;

  s2im.clear();

  rep(i,N) {

    string a,b;

    cin >> a;

    FOR(it,a) if(*it=='-') *it=' ';

    stringstream ss(a);

    ss >> a >> b;

    in[s2i(a)][s2i(b)]=1;

  }



  int n=SZ(s2im);

  rep(i,n)rep(j,n){

    bool ok=false;

    rep(k,n){

      if(in[i][k]==1 && in[j][k]==1) ok=true;

      if(in[i][k]==1 && in[k][j]==1) ok=true;

      if(in[k][i]==1 && in[j][k]==1) ok=true;

      if(in[k][i]==1 && in[k][j]==1) ok=true;

    }

    if(!ok) continue;

    ok=false;

    rep(k,n) if(in[k][i]==1 && in[j][k]==1) ok=true;

    if(ok) continue;

    rep(k,n) if(in[i][k]==1 && in[k][j]==1) ok=true;

    if(ok) continue;

    g[i][j]=g[j][i]=1;

  }

  

  rep(i,n)rep(j,n) g[i][j]=min(g[i][j],in[i][j]);

  rep(i,n)rep(j,n) if(in[i][j]==1) in[j][i]=1;





  

  rep(k,n)rep(i,n)rep(j,n){

    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

    in[i][j]=min(in[i][j],in[i][k]+in[k][j]);

  }

  



  cout << n << endl;

  cin >> M;

  rep(i, M){

    string a,b;

    cin >> a;

    FOR(it,a) if(*it=='-') *it=' ';

    stringstream ss(a);

    ss >> a >> b;

    int av=s2i(a);

    int bv=s2i(b);

    //cout << av << ' ' << bv << ' ' << g[av][bv] << ' ' << in[av][bv] << ' ' << in[bv][av] << endl;

    if(av<n && bv<n && g[av][bv]<9999 &&

       (in[av][bv]&1))cout << "YES" << endl;

    else cout << "NO" << endl;

  }

}



int main(int argc, char *argv[])

{

  while(cin >> N && N) solve();

  return 0;

}