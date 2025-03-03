#include<cstdio>

using namespace std;

char a[55][55];

int dis[55][55];

int main(){

	int n,m;

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);

	for(int i=1;i<=n;i++){

			for(int j=1;j<=m;j++){

			int ans=0;

			if(a[i-1][j-1]=='#') ans++;

			if(a[i-1][j]=='#') ans++;

			if(a[i-1][j+1]=='#') ans++;

			if(a[i][j-1]=='#') ans++;

			if(a[i][j+1]=='#') ans++;

			if(a[i+1][j-1]=='#') ans++;

			if(a[i+1][j]=='#') ans++;

			if(a[i+1][j+1]=='#') ans++;

			if(a[i][j]=='#') printf("#");

			else printf("%d",ans);

		}

		putchar('\n');

	}

}