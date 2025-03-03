#include <cstdio>

using namespace std;

const int N=2010;

struct node{int x,y;}e[N];

int n,k,ans,tot,cnt,head[N],v[N<<1],nxt[N<<1],deep[N];

inline void add(int x,int y){

    v[++tot]=y;

    nxt[tot]=head[x];

    head[x]=tot;

}inline void dfs(int x,int fx,int dep){

    deep[x]=dep;

    for(int i=head[x];i;i=nxt[i]){

        if(v[i]==fx)continue;

        dfs(v[i],x,dep+1);

}}int main(){

    scanf("%d%d",&n,&k),ans=1e9;

    for(int i=1;i<n;i++)

    	scanf("%d%d",&e[i].x,&e[i].y),add(e[i].x,e[i].y),add(e[i].y,e[i].x);

    if(k&1)

      	for(int i=1;i<n;i++){

        	cnt=0,dfs(e[i].x,e[i].y,0),dfs(e[i].y,e[i].x,0);

        	for(int j=1;j<=n;j++) if(deep[j]>(k-1)/2) cnt++;

        	if(cnt<ans) ans=cnt;} 

    else{

        for(int i=1;i<=n;i++){

	        cnt=0,dfs(i,0,0);

	      	for(int j=1;j<=n;j++) if(deep[j]>k/2) cnt++;

	      	if(cnt<ans) ans=cnt;}

    }printf("%d\n",ans);

}