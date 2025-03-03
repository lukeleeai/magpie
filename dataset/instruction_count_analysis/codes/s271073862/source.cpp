#include "stdc++.h"

using namespace std;

typedef  long long ll ;

const int maxn=1e2+3,maxxn=1e4+2;

vector<pair<int,int> >v[maxn][maxn];

bool mark[maxn][maxn];

int ans[maxn][maxn];

pair<int,int>p[maxxn];

int c;

void dfs(int u,int k){

    mark[u][k]=1;

    if(p[c].first<=0)c++;

    ans[u][k]=p[c].second;

    p[c].first--;

    for(int i=0;i<v[u][k].size();i++){

        int x1=v[u][k][i].first,y1=v[u][k][i].second;

        if(!mark[x1][y1])dfs(x1,y1);

    }

}

int main() {

    int h,w,n;

    cin>>h>>w>>n;

    for(int i=0;i<n;i++){

        int x;

        cin>>x;

        p[i]=make_pair(x,i+1);

    }

    for(int i=1;i<=h;i++){

        for(int j=1;j<=w;j++){

            if(j+1<=w)v[i][j].push_back(make_pair(i,j+1));

            if(j-1>0)v[i][j].push_back(make_pair(i,j-1));

            if(i+1<=h)v[i][j].push_back(make_pair(i+1,j));

            if(i-1>0)v[i][j].push_back(make_pair(i-1,j));

        }

    }

    dfs(1,1);

    for(int i=1;i<=h;i++){

        for(int j=1;j<=w;j++)cout<<ans[i][j]<<" ";

        cout<<endl;

    }

    return 0;

}