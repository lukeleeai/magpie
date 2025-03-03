#include <stdio.h>

#include <vector>

using namespace std;

int n,k;int inline gcd(int a, int b) {while (b) {int c=a%b;a=b,b=c;} return a;}

vector<vector<int> >g;

vector<int>mt;

vector<char>used;

bool try_kuhn(int v) {

	if (used[v]) return false;

	used[v]=1;

	for (int i=g[v].size()-1;i>=0;i--) {

		int to=g[v][i];

		if (mt[to]==-1 || try_kuhn(mt[to])) {

			mt[to]=v;return true;

		}

	}

	return false;

}

int A[505],B[505];

int main() {

	int i,j;

	while (scanf("%d %d",&n,&k)!=EOF && (n || k)) {

		g.clear();mt.assign(k,-1);g.resize(n+k);

		for (i=0;i<n;scanf("%d",&A[i++]));

		for (i=0;i<k;scanf("%d",&B[i++]));

		for (i=0;i<n;i++) for (j=0;j<k;j++) if (gcd(A[i],B[j])>1) g[i].push_back(j);

		for (i=0;i<n;i++) {

			used.assign(n,false);

			try_kuhn(i);

		}

		for (i=0,j=0;i<k;i++) if (mt[i]!=-1) j++;

		printf("%d\n",j);

	}

	return 0;

}