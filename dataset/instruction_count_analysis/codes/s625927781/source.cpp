#include<cstdio>

#include<cstring>

typedef long long ll;

const int MAXN = 100000;

struct node{

	node *ch[2];

}pl[MAXN + 5], *NIL=&pl[0], *ncnt=&pl[0], *root=&pl[0];

ll lowbit(ll x) {return x & (-x);}

void insert(char *S) {

	int len = strlen(S); node *nw = root;

	for(int i=0;i<len;i++) {

		if( nw->ch[S[i]-'0'] == NIL )

			nw->ch[S[i]-'0'] = (++ncnt), ncnt->ch[0] = ncnt->ch[1] = NIL;

		nw = nw->ch[S[i]-'0'];

	}

}

ll res; char s[MAXN + 5];

void dfs(node *rt, ll l) {

	if( rt->ch[0] == NIL && rt->ch[1] == NIL )

		return ;

	if( rt->ch[0] == NIL ) res ^= lowbit(l);

	else dfs(rt->ch[0], l-1);

	if( rt->ch[1] == NIL ) res ^= lowbit(l);

	else dfs(rt->ch[1], l-1);

}

int main() {

	root->ch[0] = root->ch[1] = NIL;

	int N; ll L; scanf("%d%lld", &N, &L);

	for(int i=1;i<=N;i++)

		scanf("%s", s), insert(s);

	dfs(root, L);

	if( res ) puts("Alice");

	else puts("Bob");

}