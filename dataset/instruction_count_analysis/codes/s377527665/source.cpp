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



int main()

{

	int N;

	while(~scanf("%d",&N)){

		printf("%d\n",800 * N - N / 15 * 200);

	}

    return 0;

}