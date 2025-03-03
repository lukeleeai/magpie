#include<cstdio>

#include<cctype>

#include<algorithm>

using namespace std;

int n,t[2],a[5][100010],to[100010];

char buffer[10000010],*hed,*tal;

inline char Getchar(){

	return *hed++;

}

inline int rd(){

	register int x=0;

	char c;

	do c=Getchar();

	while(!isdigit(c));

	do{

		x=(x<<1)+(x<<3)+(c^48);

		c=Getchar();

	}while(isdigit(c));

	return x;

}

inline int abs(int x){

	return x>=0?x:-x;

}

int main(){

	int len=fread(buffer,1,10000000,stdin);

	hed=buffer,tal=buffer+len;

	n=rd();

	for(int i=1;i<=3;i++)

		for(int j=1;j<=n;j++)

			a[i][j]=rd();

	for(register int i=1;i<=n;i++){

		to[i]=a[2][i]/3+1;

		if(!((a[1][i]-a[2][i]==-1&&a[2][i]-a[3][i]==-1&&a[1][i]%3==1)||(a[1][i]-a[2][i]==1&&a[2][i]-a[3][i]==1&&!(a[1][i]%3)))||(abs(i-to[i])&1)){

			puts("No");

			return 0;

		}

		t[i&1]^=(a[1][i]>a[2][i]);

	}

	for(register int i=1;i<=n;i++){

		while(to[i]!=i){

			t[i&1^1]^=1;

			swap(to[i],to[to[i]]);

		}

	}

	puts(t[0]||t[1]?"No":"Yes");

	return 0;

}