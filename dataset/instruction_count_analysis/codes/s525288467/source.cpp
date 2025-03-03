#include <stdio.h>

int n,m,q,a,b,c,d,rui[1005][1005][3],ret[3];char f[1005][1005],e[3]={'J','O','I'};

int main(){

	scanf("%d%d%d",&n,&m,&q);

	for(int i=0;i<n;i++) scanf("%s",&f[i]);

	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<3;k++)

	rui[i][j][k]=rui[i-1][j][k]+rui[i][j-1][k]-rui[i-1][j-1][k]+(f[i-1][j-1]==e[k]);

	for(int i=0;i<q;i++){

		scanf("%d%d%d%d",&a,&b,&c,&d);

		for(int j=0;j<3;j++) ret[j]=rui[c][d][j]-rui[c][b-1][j]-rui[a-1][d][j]+rui[a-1][b-1][j];

		printf("%d %d %d\n",ret[0],ret[1],ret[2]);

	}

}