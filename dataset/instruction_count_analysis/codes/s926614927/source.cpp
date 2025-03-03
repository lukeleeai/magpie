#include"stdc++.h"

#define rep(i,n)for(int i=0;i<n;i++)

#define EPS (1e-10)

#define MOD 1000000007

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

typedef pair<int, int>P;



int s[100000];

int main() {

	int n; scanf("%d", &n);

	int cnt = 0;

	for(int i=1;i<=n;i++) {

		int a; scanf("%d", &a);

		if (s[a] == i)cnt++;

		s[i] = a;

	}

	printf("%d\n", cnt);

}