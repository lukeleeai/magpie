#include"stdc++.h"

#define reg register

typedef long long ll;

using namespace std;

const int MN=2e5+5;

int deg[MN][2];

int n,m;

char ch[MN];

int to[MN<<1],nxt[MN<<1],h[MN],cnt;

inline void ins(int s,int t){

	to[++cnt]=t;nxt[cnt]=h[s];h[s]=cnt;

	to[++cnt]=s;nxt[cnt]=h[t];h[t]=cnt;

}

int que[MN],ta;

int main(){

	scanf("%d%d",&n,&m);scanf("%s",ch+1);

	for(reg int i=1,s,t;i<=m;i++){

		scanf("%d%d",&s,&t);ins(s,t);

		deg[s][ch[t]-'A']++;deg[t][ch[s]-'A']++;

	}

	for(reg int i=1;i<=n;i++)

		if(!deg[i][0]||!deg[i][1])que[++ta]=i;

	for(reg int i=1;i<=ta;i++)

		for(reg int j=h[que[i]];j;j=nxt[j])

			if(deg[to[j]][0]&&deg[to[j]][1]&&!(--deg[to[j]][ch[que[i]]-'A']))

				que[++ta]=to[j];

	puts(ta<n?"Yes":"No");

	return 0;

}