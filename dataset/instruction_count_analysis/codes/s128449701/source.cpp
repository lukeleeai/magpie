#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <string>

#include <cmath>

#include <algorithm>

#include <vector>

#include <map>

#include <queue>

#include <set>

using namespace std;

typedef long long LL;

const int MaxN = 1e5;

const int Inf = 1 << 30;



int a[MaxN + 5];



int main()

{

	int n,p;

	while(~scanf("%d",&n)){

		for(int i = 1;i <= n;i++) scanf("%d",&a[i]);

		sort(a + 1,a + 1 + n);p = 0;

		for(int i = 2;i <= n;i++) if(a[i] == a[i - 1]) p++;

		p = p + (p % 2 == 0 ? 0 : 1);

		printf("%d\n",n - p);

	}

    return 0;

}