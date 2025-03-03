#include<cstdio>

#include<cstring>

char op[10];

int n,a[4001];

int b[4001][2],bit[4001];

bool c[4001];

int f[2001][2001];

int Min(int a,int b){

	return a<b?a:b;

}

void Add(int x,int ad){

	for(int i=x;i<=n+n;i+=(i&(-i))) bit[i]+=ad;

	

}

int query(int x){

	int sum=0;

	for(int i=x;i;i-=(i&(-i))) sum+=bit[i];

	return sum;

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n+n;i++){

		scanf("%s%d",op,&a[i]);

		if(op[0]=='W') c[i]=0;else c[i]=1;

		b[a[i]][c[i]]=i;

	}

	memset(f,127/3,sizeof(f));

	f[0][0]=0;

	for(int i=0;i<=n;i++){

		memset(bit,0,sizeof(bit));

		for(int j=1;j<=n+n;j++) Add(j,1);

		for(int j=1;j<=i;j++) Add(b[j][0],-1);

		for(int j=0;j<=n;j++){

			if(j>0) Add(b[j][1],-1);

			if(i>0) f[i][j]=Min(f[i][j],f[i-1][j]+query(b[i][0]));

			if(j>0) f[i][j]=Min(f[i][j],f[i][j-1]+query(b[j][1]));

		}

	}

	printf("%d",f[n][n]);

	return 0;

}