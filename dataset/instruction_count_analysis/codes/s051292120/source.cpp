#include <cstdio>

#include <algorithm>



using namespace std;



const int maxn = 1e5+5;

const int mod = 1000000007;



int n,m;

int a[maxn];

int f[maxn];



int main() {

	scanf("%d %d",&n,&m);

	for (int i = 1; i <= m; i++) {

		scanf("%d",&a[i]);

	}

	sort(a+1,a+1+m);

	int p = 1;

	f[0] = 1;

	if (a[p] != 1) {

		f[1] = 1;

	}else{

		p++;

	}

	for (int i = 2; i <= n; i++) {

		if (a[p] == i) {

			f[i] = 0;

			++p;

			continue;

		}else{

			f[i] = (f[i-1] + f[i-2])%mod;

		}

	}

	printf("%d\n",f[n]);

}