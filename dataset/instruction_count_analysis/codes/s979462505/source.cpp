#include"stdc++.h"

using namespace std;

typedef long long LL;



const int N=1e5+100;

int n,a[N];

char op[N];

LL f[N][3];



void cmax(LL &x,LL y) {x=x>y?x:y;}



int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;++i)

	{

		scanf("%d",&a[i]); op[i]='!';

		if(i == n) break;

		while(op[i] != '+' && op[i] != '-') op[i]=getchar();

	}

	memset(f,0xcf,sizeof(f)); f[1][0]=a[1];

	for(int i=1;i<n;++i)

	{

		if(op[i] == '-') cmax(f[i+1][1],f[i][0]-a[i+1]);

		if(op[i] == '+') cmax(f[i+1][0],f[i][0]+a[i+1]);

		if(op[i] == '-') cmax(f[i+1][0],f[i][0]-a[i+1]);

		

		if(op[i] == '+') cmax(f[i+1][1],f[i][1]-a[i+1]);

		if(op[i] == '-') cmax(f[i+1][1],f[i][1]+a[i+1]);

		//if(op[i] == '-') cmax(f[i+1][1],f[i][1]-a[i+1]);

		if(op[i] == '-') cmax(f[i+1][2],f[i][1]+a[i+1]);

		if(op[i] == '+') cmax(f[i+1][0],f[i][1]+a[i+1]);

		if(op[i] == '-') cmax(f[i+1][0],f[i][1]-a[i+1]);

		

		if(op[i] == '+') cmax(f[i+1][2],f[i][2]+a[i+1]);

		//if(op[i] == '-') cmax(f[i+1][2],f[i][2]-a[i+1]);

		if(op[i] == '-') cmax(f[i+1][2],f[i][2]+a[i+1]);

		if(op[i] == '+') cmax(f[i+1][0],f[i][2]+a[i+1]);

		if(op[i] == '-') cmax(f[i+1][0],f[i][2]-a[i+1]);

		if(op[i] == '-') cmax(f[i+1][1],f[i][2]-a[i+1]);

	}

	printf("%lld",max(f[n][0],max(f[n][1],f[n][2])));

	return 0;

}