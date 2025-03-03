#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef pair<int,int> pii;

#define pb push_back

#define mp make_pair

#define fi first

#define se second

#define sz(a) int(a.size())

const int N=50;



int gi() {

	int x=0,o=1;char ch=getchar();

	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();

	if(ch=='-') o=-1,ch=getchar();

	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();

	return x*o;

}



int n;

ll f[N][N][N],g[N][N][N];

char s[N][N];



int main() {

	cin>>n;n<<=1;

	for(int i=1;i<=n;i++) {

		scanf("%s",s[i]+1),f[i][i][i]=1;

		for(int x=1;x<i;x++) if(s[x][i]=='1') g[i][i][x]=1;

	}

	for(int len=3;len<=n;len+=2)

		for(int l=1;l<=n-len+1;l++) {

			int r=l+len-1;

			for(int a=l;a<r;a+=2)

				for(int b=r;b>a;b-=2) {

					ll sum=0;

					for(int x=l;x<=a;x++) sum+=f[l][a][x]*g[b][r][x];

					for(int t=a+1;t<b;t++) f[l][r][t]+=f[a+1][b-1][t]*sum;

				}

			for(int x=1;x<l;x++)

				for(int y=l;y<=r;y++) if(s[x][y]=='1') g[l][r][x]+=f[l][r][y];

		}

	ll ans=0;

	for(int i=2;i<=n;i++) if(s[1][i]=='1') ans+=f[2][n][i];

	cout<<ans;

	return 0;

}
