#include <stdio.h>

#define N 505

int A[N],B[N],g[N][N],n,k,mt[N],used[N];

int inline gcd(int a, int b) {while (b) {int c=a%b;a=b,b=c;} return a;}

int kuhn(int v) {if (used[v]) return 0;used[v]=1;for (int i=g[v][0]-1;i;i--) {int to=g[v][i];if (mt[to]==-1 || kuhn(mt[to])) {mt[to]=v;return 1;}}return 0;}

int main() {

	int i,j;while (scanf("%d %d",&n,&k)!=EOF && (n || k)) {

		for (i=0;i<k;mt[i++]=-1);

		for (i=0;i<n;g[i][0]=1,scanf("%d",&A[i++]));for (i=0;i<k;scanf("%d",&B[i++]));

		for (i=0;i<n;i++) for (j=0;j<k;j++) if (gcd(A[i],B[j])>1) g[i][g[i][0]++]=j;

		for (i=0;i<n;i++) {for (j=0;j<n;used[j++]=0);kuhn(i);}

		for (i=0,j=0;i<k;j+=(mt[i]!=-1),i++);printf("%d\n",j);

	}

	return 0;

}