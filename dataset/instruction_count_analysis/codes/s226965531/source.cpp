#include <cstdio>

#include <string>

#include <cstring>

#include <cstdlib>

#include <algorithm>

#define mxn 12

#define mxm 26

using namespace std;

char s[mxn][mxn];

int n,m,p[mxn],a[mxn];

string t[mxn|1];

bool mirror(int l,int r) {

	for(int i=0;i<n;i++)

		if(s[i][l]!=s[p[i]][r])

			return 0;

	return 1;

}

void dfscol(int d,bool b) {

	if(d==m) {	puts("YES");	exit(0);	}

	if(~a[d]) {	dfscol(d+1,b);	return;	}

	for(int i=d+1;i<m;i++)

		if(a[i]==-1&&mirror(d,i)) {

			a[d]=i,a[i]=d;

			dfscol(d+1,b);

			a[d]=-1,a[i]=-1;

		}

	if(b&&mirror(d,d))	a[d]=d,dfscol(d+1,0),a[d]=0;

}

void dfsrow(int d,bool b) {

	if(d==n) {	dfscol(0,m&1);	return;	}

	if(~p[d]) {	dfsrow(d+1,b);	return;	}

	for(int i=d+1;i<n;i++)

		if(p[i]==-1&&t[d]==t[i]) {

			p[d]=i,p[i]=d;

			dfsrow(d+1,b);

			p[d]=-1,p[i]=-1;

		}

	if(b)	p[d]=d,dfsrow(d+1,0),p[d]=0;

}

int main() {

	memset(p,-1,sizeof(p));

	memset(a,-1,sizeof(a));

	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++) {

		scanf("%s",s[i]);

		for(int j=0;j<m;j++)

			t[i]+=s[i][j];

		sort(t[i].begin(),t[i].end());

	}

	dfsrow(0,n&1);

	puts("NO");

	return 0;

}