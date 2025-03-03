#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;



typedef long long ll;

const int MAXN=1e5+5;



int n,m,flag;

int cnt[3],ncnt,ecnt,c[MAXN];

bool vis[MAXN],evis[MAXN];

struct node{

    int v,w,id;

    node(int _v,int _w,int _id):v(_v),w(_w),id(_id){}

};

vector<node> E[MAXN];



void dfs(int u){

    vis[u]=1;

    ncnt++;

    cnt[c[u]]++;

    for(int i=0;i<(int)E[u].size();i++){

        int v=E[u][i].v,w=E[u][i].w,id=E[u][i].id;

        if(evis[id]) continue; evis[id]=1; ecnt++;

        if(!vis[v]){

            c[v]=(c[u]+w+3)%3;

            dfs(v);

        }

        else if(c[v]!=(c[u]+w+3)%3) flag=1;

    }

}



int main(){



	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++){

	    int u,v;

        scanf("%d%d",&u,&v);

        E[u].push_back(node(v,1,i));

        E[v].push_back(node(u,-1,i));

	}

	ll ans=0;

    for(int i=1;i<=n;i++){

        if(vis[i]) continue;

        flag=ncnt=ecnt=cnt[0]=cnt[1]=cnt[2]=0;

        dfs(i);

        if(flag) ans+=1ll*ncnt*ncnt;

        else if(!cnt[0]||!cnt[1]||!cnt[2]) ans+=ecnt;

        else ans+=1ll*cnt[0]*cnt[1]+1ll*cnt[1]*cnt[2]+1ll*cnt[2]*cnt[0];

    }

    printf("%lld",ans);



	fclose(stdin);

	fclose(stdout);

}
