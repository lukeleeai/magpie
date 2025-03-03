#include <iostream>

#include <string>

#include <vector>

#include <set>

#include <algorithm>

#include <cctype>

#include <cmath>

#include <queue>

#include <map>

#include <numeric>

#include <unordered_map>

#include <iomanip>

#include <functional>

#include <bitset>

#include <complex>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)

#define all(x) (x).begin(),(x).end()



template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



typedef long long ll;



using namespace std;

vector<int>ok(600000,0),memo(600000,-1),fl(600000,0);

int inf=1e9+7,res=0;



int dfs(int node,int sl,int tl)

{

//  cout<<node<<" "<<fl[node]<<memo[node]<<endl;



  if(fl[node]==1&&memo[node]==-1)return inf;

  if(memo[node]>-1)return memo[node];

  fl[node]=1;

  int r=0;

  if(ok[node])r=dfs((node+tl)%sl,sl,tl)+1;

  else r=0;

  return memo[node]=r;

}

int main()

{

  ios::sync_with_stdio(false);

  cin.tie(0);

  string t,s;

  cin>>s;

  cin>>t;

  int l=t.length(),sl=s.length();

  vector<int>A(l+1);

  A[0] = -1;

  int j = -1;

  for (int i = 0; i < t.size(); i++)

  {

    while (j >= 0 && t[i] != t[j]) j = A[j];

    j++;

    if (j>0&&t[i+1] == t[j]) A[i+1] = A[j];else A[i+1] = j;

  }

  rep(i,l+1)A[i]=i-A[i];

  int m=0,i=0;

  while(m<sl)

  {

    if(t[i]==s[(m+i)%sl])

    {

      i++;

      if(i==l)ok[m]=1;

    }

    else

    {

      m+=A[i];

      if(i>0)i=i-A[i];

    }



  }

//  rep(i,sl)cout<<ok[i]<<endl;



  rep(i,sl)dfs(i,sl,l);

  rep(i,sl)chmax(res,memo[i]);

  //rep(i,sl)cout<<memo[i]<<endl

  if(res>=inf)res=-1;

  cout<<res<<endl;



  return 0;



}
