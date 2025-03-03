#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<math.h>

#include<complex>

#include<queue>

#include<deque>

#include<map>

#include<set>

#include<bitset>

using namespace std;

#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )

#define rep(i,n) REP(i,0,n)

typedef long long ll;

typedef pair<int,int> pint;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;

int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;



int n,m,used[101010],cmp[101010];

vector<int> v[101010],rv[101010],vs;



void dfs(int x){

   used[x]=true;

   rep(i,v[x].size())if(!used[v[x][i]])dfs(v[x][i]);

   vs.push_back(x);

}



void rdfs(int x,int k){

   used[x]=true;

   cmp[x]=k;

   rep(i,rv[x].size())if(!used[rv[x][i]])rdfs(rv[x][i],k);

}



int scc(){

   rep(i,n)if(!used[i])dfs(i);

   rep(i,n)used[i]=0;

   reverse(vs.begin(),vs.end());

   int k=0;

   rep(i,vs.size())if(!used[vs[i]])rdfs(vs[i],k++);

   return k;

}







int main(){

    cin>>n>>m;

    rep(i,m){

        int s,t;

        cin>>s>>t;

        v[s].push_back(t);

        rv[t].push_back(s);

    }

    scc();

    int q;

    cin>>q;

    rep(i,q){

        int s,t;

        cin>>s>>t;

        cout<<(cmp[s]==cmp[t])<<endl;

    }

    return 0;

}
