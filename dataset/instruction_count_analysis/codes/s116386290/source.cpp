#include"stdc++.h"

using namespace std;

const int N=100010;

inline char nc(){

    static char buf[100000],*p1=buf,*p2=buf;

    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;

}

inline int read(){

    char ch=nc();int sum=0;

    while(!(ch>='0'&&ch<='9'))ch=nc();

    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();

    return sum;

}

struct E{

	int t,xt;

}e[N<<1];



int h[N],cnt;



void adge(int f,int t){

	e[++cnt]=(E){t,h[f]};h[f]=cnt;

}



int dp[N][2],dan[N];



void dfs1(int u,int fa){	

	for(int i=h[u];~i;i=e[i].xt) if(e[i].t!=fa){

		dfs1(e[i].t,u);

		if(dan[e[i].t]) dp[u][1]++;

		else dp[u][0]++;

	}

	if(dp[u][1]+dp[u][0]==0){

		dan[u]=1;

	}

	else if(dp[u][1]>1){

			puts("First");

			exit(0);

	}

	else if(dp[u][1]==1){

		dan[u]=0;

	}

	else if(dp[u][1]==0){

		dan[u]=1;

	}

}

			

void dfs2(int u,int fa){

	if(dp[u][1]!=1){

		puts("First");

		exit(0);

	}

	for(int i=h[u];~i;i=e[i].xt) if(e[i].t!=fa){

		int t[2];

		t[0]=dp[u][0]-(!dan[e[i].t]);

		t[1]=dp[u][1]-dan[e[i].t];

		if(t[1]+t[0]==0){

			dp[e[i].t][1]++;

		}

		else if(t[1]==1){

			dp[e[i].t][0]++;

		}

		else if(t[1]==0){

			dp[e[i].t][1]++;

		}

		dfs2(e[i].t,u);	

	}

}

		

int main(){

	memset(h,cnt=-1,sizeof(h));

	int n;

	n=read();

	for(int i=1;i<n;i++){

		int a,b;

		a=read();

		b=read();

		adge(a,b);

		adge(b,a);

	}

	dfs1(1,1);

	dfs2(1,1);

	puts("Second");

	return 0;

}
