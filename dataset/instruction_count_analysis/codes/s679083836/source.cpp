#include <stdio.h>

#include <cmath>

#include <algorithm>

#include <cfloat>

#include <stack>

#include <queue>

#include <vector>

#include <string>

#include <iostream>

#include <set>

#include <map>

#include <time.h>

using namespace std;

typedef long long int ll;

typedef unsigned long long int ull;

typedef pair<int,int> P;

typedef pair<ll,pair<ll,ll>> p;

#define BIG_NUM 2000000000

#define MOD 1000000007

#define EPS 0.000000001

#define bit(n,k) ((n>>k)&1) /*nのk bit目*/

#define FOR(x,to) for(x=0;x<to;x++)

#define FORR(x,arr) for(auto& x:arr)

#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

#define ALL(a) (a.begin()),(a.end())

#define ZERO(a) memset(a,0,sizeof(a))

#define MINUS(a) memset(a,0xff,sizeof(a))

static const int MAX_SIZE = 1 << 17; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5



int N;

set<int> S[100010];

int T[110000];

vector<int> C;



int main(){

   int i,j,k,l,r,x,y;

   string s;

   cin>>N;



   FOR(i,N-1){

       cin>>x>>y;

       S[x-1].insert(y-1);

       S[y-1].insert(x-1);

   }



   FOR(i,N){

       cin>>x;

       C.push_back(x);

   }

   sort(ALL(C));

   set<P> cand;

   FOR(i,N) cand.insert({(int)S[i].size(),i});

   ll ret=0;

   FORR(c,C){

       x=cand.begin()->second;

       cand.erase(cand.begin());

       T[x]=c;

       ret+=1LL*c*S[x].size();

       FORR(s,S[x]){

           cand.erase({(int)S[s].size(),s});

           S[s].erase(x);

           cand.insert({(int)S[s].size(),s});

       }

   }

   cout<<ret<<endl;

   FOR(i,N) cout<<T[i]<<" ";

   cout<<endl;

}


