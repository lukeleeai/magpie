#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <cstring>

#include <map>

#include <utility>

#include <set>

#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <sstream>

#include <complex>

#include <stack>

#include <queue>



using namespace std;

typedef long long LL;

typedef pair<string, string> PSS;

static const double EPS = 1e-8;

static const int INF = (int)1e8;



#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)

#define REP(i,n) for (int i=0; i<(int)(n); ++i)

#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define FIND(m,w) ((m).find(w)!=(m).end())



bool eql(string s1,string s2){

  REP(i,s1.size()){

    if(s1[i]!=s2[i]&&s2[i]!='?'&&s1[i]!='?'){

      return false;

    }

  }

  return true;

}

struct Ans{

  string s1,s2,s3;

  Ans (string s1,string s2,string s3) : s1(s1),s2(s2),s3(s3) {}

};

int main(void){

  int n,m;

  while(cin>>n>>m,(n||m)){

    bool pord[1025];

    PSS adress[1025];

    REP(i,n){

      string tmp1,tmp2;

      cin>>tmp1;

      if(tmp1=="permit") pord[i] = true;

      else pord[i] = false;

      cin>>tmp1>>tmp2;

      adress[i] = PSS(tmp1,tmp2);

    }

    vector<Ans> ans;

    REP(i,m){

      string s1,s2,s3;

      cin>>s1>>s2>>s3;

      bool ligal = false;

      REP(i,n){

        if(eql(s1,adress[i].first)&&eql(s2,adress[i].second)){

          ligal = pord[i];

        }

      }

      if(ligal){

        ans.push_back(Ans(s1,s2,s3));

      }

    }

    cout<<ans.size()<<endl;

    REP(i,ans.size()){

      cout<<ans[i].s1<<" "<<ans[i].s2<<" "<<ans[i].s3<<endl;

    }

  }

  return 0;

}