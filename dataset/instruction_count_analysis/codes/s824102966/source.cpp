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

const LL mod = 1e9 + 7;



int main()

{

	int a,b,w;

	while(~scanf("%d%d%d",&w,&a,&b)){

		if(a > b) swap(a,b);

		a = b - w - a;

		if(a < 0) a = 0;

		printf("%d\n",a);

	}

    return 0;

}