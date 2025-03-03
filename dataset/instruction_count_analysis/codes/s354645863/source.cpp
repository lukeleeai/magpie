#include<cstdio>

#include<algorithm>

#include<cmath>

#include<vector>

using namespace std;

int n,m,l,r,ans,q;

int a[1000][1000];

int main(){

	scanf("%d%d%d",&n,&m,&q);

	for (int i=1;i<=m;++i){

		scanf("%d%d",&l,&r);

		a[l][r]++;

	}

	for (int i=1;i<=n;++i)

		for (int j=1;j<=n;++j) a[i][j]+=a[i][j-1];

		

	for (int i=1;i<=q;++i){

		scanf("%d%d",&l,&r);

		int ans=0;

		for (int j=l;j<=r;++j){

			ans+=a[j][r];

		}

		printf("%d\n",ans);

	}

}