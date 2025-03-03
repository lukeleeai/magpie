#include<cstdio>

#include<cstring>

#include<vector>

using namespace std;

int n,m,u[210000],v[210000],tmp[1100][2];

bool ans1[1100][1100],ans2[1100][1100];

vector<int> vec[1100];

void dfs(int u,int rt){

    ans1[rt][u]=true;

    for(int i=0;i<vec[u].size();i++)

        if (!ans1[rt][vec[u][i]]) dfs(vec[u][i],rt);

}

void dfs2(int u,int num,int f){

    tmp[u][f]=num;

    for(int i=0;i<vec[u].size();i++)

        if (!tmp[vec[u][i]][f]) dfs2(vec[u][i],num,f);

}

int main(){

    scanf("%d%d",&n,&m);

    for (int i=1;i<=m;i++){

        scanf("%d%d",&u[i],&v[i]);

        vec[u[i]].push_back(v[i]);

    }

    for (int i=1;i<=n;i++) dfs(i,i);

    for (int i=1;i<=n;i++){

        memset(tmp,0,sizeof(tmp));

        tmp[i][0]=-1; tmp[i][1]=-1;

        for (int j=0;j<vec[i].size();j++)

            if (!tmp[vec[i][j]][0]) dfs2(vec[i][j],j+1,0);

        for (int j=vec[i].size()-1;j>=0;j--)

            if (!tmp[vec[i][j]][1]) dfs2(vec[i][j],j+1,1);

        for (int j=0;j<vec[i].size();j++)

            if (tmp[vec[i][j]][0]!=j+1||tmp[vec[i][j]][1]!=j+1) ans2[i][vec[i][j]]=true;

    }

    for (int i=1;i<=m;i++)

        if (ans1[v[i]][u[i]]==ans2[u[i]][v[i]]) puts("same");

        else puts("diff");

    

    return 0;

}