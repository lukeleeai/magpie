#include"stdc++.h"

using namespace std;

const int N=42;

typedef long long ll;



int gi() {

	int x=0,o=1;char ch=getchar();

	while(!isdigit(ch)&&ch!='-') ch=getchar();

	if(ch=='-') o=-1,ch=getchar();

	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();

	return x*o;

}



int n;

char s[N][N];

ll f[N][N][N];



ll dp(int l,int r,int m) {

	if(~f[l][r][m]) return f[l][r][m];

	if(l==r) return 1;

	if(l==m||r==m) return 0;

	ll &ret=f[l][r][m];ret=0;

	for(int i=l;i<m;i++)

		for(int j=m+1;j<=r;j++)

			if(s[i][j]=='1')

				for(int u=i;u<m;u++)

					for(int v=m+1;v<=j;v++) ret+=dp(l,u,i)*dp(u+1,v-1,m)*dp(v,r,j);

	return ret;

}



int main() {

	n=gi();

	for(int i=1;i<=n+n;i++) scanf("%s",s[i]+1);

	memset(f,-1,sizeof(f));

	ll ans=0;

	for(int i=2;i<=n+n;i++) if(s[1][i]=='1') ans+=dp(2,n+n,i);

	cout<<ans;

	return 0;

}
