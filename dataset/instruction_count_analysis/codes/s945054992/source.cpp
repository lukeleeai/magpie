#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<math.h>

#include<complex>

#include<queue>

#include<deque>

#include<stack>

#include<map>

#include<set>

#include<bitset>

#include<functional>

using namespace std;

#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )

#define rep(i,n) REP(i,0,n)

typedef long long ll;

typedef pair<int,int> pint;

typedef pair<ll,int> pli;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;



vector<int> v[101010];

priority_queue<int> ret[101010];

int ans[101010];



int dfs(int x,int p){

    ret[x].push(0);

    for(auto to:v[x]){

        if(to==p)continue;

        ret[x].push(dfs(to,x));

    }

    return ret[x].top()+1;

}



void dfs2(int x,int p){

    int res=ret[x].top();

    if(p!=-1){

        int y=ret[p].top();

        ret[p].pop();

        if(y!=res+1)ret[x].push(y+1);

        else ret[x].push(ret[p].top()+1);

        ret[p].push(y);

    }

    for(auto to:v[x]){

        if(to==p)continue;

        dfs2(to,x);

    }

    ans[x]=ret[x].top();

}



int main(){

    int n;

    cin>>n;

    rep(i,n-1){

        int a,b;

        cin>>a>>b;

        --a;--b;

        v[a].push_back(b);

        v[b].push_back(a);

    }

    dfs(0,-1);

    dfs2(0,-1);

    rep(i,n)cout<<2*(n-1)-ans[i]<<endl;

    return 0;

}
