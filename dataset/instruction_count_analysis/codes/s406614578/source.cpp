#include"stdc++.h"

#define reg register

typedef unsigned long long ll;

using namespace std;

const int MN=80000;

int n,pri[2001],cnt,vis[MN+5],id[501][501][2];

ll a[501][501];

inline bool border(int i){return (i==1||i==n);}

int main(){

	scanf("%d",&n);

	for(reg int i=2;i<=MN;i++){

		if(!vis[i])pri[++cnt]=i;

		if(cnt==1000)break;

		for(reg int j=1;j<=cnt&&pri[j]*i<=MN;j++){

			vis[pri[j]*i]=1;

			if(!(i%pri[j]))break;

		}

	}

	if(n==2)return 0*puts("4 7\n23 10");

	for(reg int i=1;i<=n;i++)

		for(reg int j=1;j<=n;j++)

			if((~(i+j))&1){

				id[i][j][0]=(i+j)>>1;

				id[i][j][1]=n+((i-j+n)>>1)+1;

			}

	for(reg int i=1;i<=n;i++)

		for(reg int j=1;j<=n;j++)

			if((~(i+j))&1){

				a[i][j]=1ll*pri[id[i][j][0]]*pri[id[i][j][1]];

			}

			else{

				if(border(i)&&border(j))

					if(i==1)a[i][j]=1ll*pri[id[2][n][0]]*pri[id[1][n-1][0]]*pri[id[1][n-1][1]];

					else a[i][j]=1ll*pri[id[n][2][0]]*pri[id[n-1][1][0]]*pri[id[n-1][1][1]];

				else if(border(i))

					a[i][j]=1ll*pri[id[i][j-1][0]]*pri[id[i][j+1][0]]*pri[id[i][j-1][1]]*pri[id[i][j+1][1]];

				else a[i][j]=1ll*pri[id[i-1][j][0]]*pri[id[i+1][j][0]]*pri[id[i-1][j][1]]*pri[id[i+1][j][1]];

				a[i][j]++;

			}

	for(reg int i=1;i<=n;i++,puts(""))

		for(reg int j=1;j<=n;j++)

			printf("%llu ",a[i][j]);

	return 0;

}