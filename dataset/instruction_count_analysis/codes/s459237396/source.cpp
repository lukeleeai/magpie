#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

using namespace std;

typedef long long ll;

const int maxn=100005,maxm=400005;

int last[maxn],pre[maxm],other[maxm],t,cal[maxn],vis[maxn],q[maxn],head,tail;

void add(int x,int y){++t;pre[t]=last[x];last[x]=t;other[t]=y;}

int main(){

	int n,m,x,y;

	while(cin>>n>>m){

		ll I=0,P=0,Q=0;

		memset(last,0,sizeof(last));t=0;memset(vis,0,sizeof(vis));

		memset(pre,0,sizeof(pre));memset(other,0,sizeof(other));

		for(int i=1;i<=m;++i){

				scanf("%d%d",&x,&y);add(x,y);add(y,x);

		}

		for(int i=1;i<=n;++i)if(!vis[i]){

				head=tail=0;q[++tail]=i;cal[i]=0;vis[i]=1;

				bool flag=1;

				while(head<tail){

    	              int u=q[++head];

    	              for(int j=last[u];j;j=pre[j]){

    	                     int v=other[j];

    	                     if(!vis[v]){

            	                q[++tail]=v;vis[v]=1;cal[v]=cal[u]+1;

           	              	 }

							 else{

								 if((cal[v]-cal[u])%2==0)flag=0;

							 }

                       }

	            }

	  			if(head==1){++I;continue;}

	  			if(flag)++Q;

	  			else ++P;

		}

		cout<<2ll*I*n-I*I+P*P+2ll*P*Q+2ll*Q*Q<<endl;

    }

	return 0;

}
