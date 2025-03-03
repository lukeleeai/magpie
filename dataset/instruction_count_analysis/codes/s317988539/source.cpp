#include<cstdio>

#define sc scanf

#define maxn 505

char mp[maxn][maxn];

int n,m;

int a[maxn][maxn],b[maxn][maxn];

inline char inchar(){

	char ch=getchar();

	while(ch!='#'&&ch!='.') ch=getchar();

	return ch;

}

void readin(){

	sc("%d%d",&n,&m);

	char tp;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			tp=inchar(),a[i][j]=(tp=='#'),b[i][j]=(tp=='#');



}



void work(){

	for(int i=1;i<=n;i++)

		a[i][1]=1,b[i][m]=1;



	for(int i=1;i<=n;i++){

		if(i&1){

			for(int j=1;j<m;j++)

				a[i][j]=1;

		}

	}



	for(int i=1;i<=n;i++){

		if((i&1)==0){

			for(int j=2;j<=m;j++)

				b[i][j]=1;

		}

	}

	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++)

			if(a[i][j]) putchar('#');

			else putchar('.');

		putchar(10);

	}

	putchar(10);

	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++)

			if(b[i][j]) putchar('#');

			else putchar('.');

		putchar(10);

	}



}



int main(){

	readin();

	work();

}