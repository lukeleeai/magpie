#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

const int inf=1e8,maxn=305;

inline int read(){int x=0,f=1; char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f;}

int n,m,ans,cnt[maxn],a[maxn][maxn];

bool cho[maxn];

inline void init(){

	n=read(); m=read();

	for (int i=1;i<=n;i++){

		for (int j=1;j<=m;j++){

			a[i][j]=read();

		}

	}

	ans=inf;

	memset(cho,1,sizeof(cho));

	for (int k=1;k<=m;k++){

		memset(cnt,0,sizeof(cnt));

		for (int i=1;i<=n;i++){

			for (int j=1;j<=m;j++){

				if (cho[a[i][j]]){

					cnt[a[i][j]]++;

					break;

				}

			}

		}

		int mx=0;

		for (int i=1;i<=m;i++){

			if ((!mx)||(mx&&cnt[mx]<cnt[i])){

				mx=i;

			}

		}

		cho[mx]=0;

		ans=min(cnt[mx],ans);

	}

	printf("%d\n",ans);

}

int main(){

	init();

	return 0;

}