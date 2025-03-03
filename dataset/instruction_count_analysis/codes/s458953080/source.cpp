#include <cstdio>



inline void cmin(int&x, const int&y) {x > y && (x = y);}

inline void cmax(int&x, const int&y) {x < y && (x = y);}



const int N = 2003;

int arr[N], brr[N];

char str[N];

int a[N][N];

int fl[N][N], fr[N][N];

int n, m;



int main() {

	scanf("%d%d",&n,&m);

	scanf("%s", str+1);

	for(int i=1;i<=m;++i) arr[i] = str[i] == '#';

	for(int i=1;i<n;++i) {

		scanf("%s", str+1);

		for(int j=1;j<=m;++j) brr[j] = str[j] == '#';

		for(int j=1;j<m;++j) a[i][j] = !(arr[j] xor arr[j+1] xor brr[j] xor brr[j+1]);

		for(int j=1;j<=m;++j) arr[j] = brr[j];

	}

	

	int Ans = n > m ? n : m; --n, --m;

	for(int i=1;i<=n;++i) {

		for(int j=1;j<=m;++j) if(a[i][j])

			fl[i][j] = fl[i][j-1] + 1;

		for(int j=m;j;--j) if(a[i][j])

			fr[i][j] = fr[i][j+1] + 1;

	}

	

	

	for(int i=0;i<n;++i)

	for(int j=1;j<=m;++j) if(!a[i][j]) {

		int ml = 1e9, mr = 1e9;

		for(int k=i+1;k<=n;++k) {

			if(!a[k][j]) break;

			cmin(ml, fl[k][j]), cmin(mr, fr[k][j]);

			cmax(Ans, (ml+mr) * (k-i+1));

		}

	}

	

	printf("%d\n", Ans);

	return 0;

}