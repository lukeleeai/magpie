#include <stdio.h>

#include <string>

#include <cstring>

#include <stdlib.h>

#include <math.h>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <list>

#include <iterator>

#include <assert.h>

#pragma warning(disable:4996) 

 

typedef long long ll;

#define MIN(a, b) ((a)>(b)? (b): (a))

#define MAX(a, b) ((a)<(b)? (b): (a))

#define LINF 9223300000000000000

#define INF 2140000000

const long long MOD = 1000000007;

//const long long MOD = 998244353;

 

using namespace std;



char str[30005];



void solve()

{

	int n;

	scanf("%d%s", &n, str);

	

	int flag[10] = { 0 };

	int flag2[100] = { 0 };

	int flag3[1000] = { 0 };

	int i,j;

	for (i = 0; i < n; i++) {

		int tmp = str[i] - '0';

		for (j = 0; j < 100; j++) {

			if (flag2[j]) flag3[j * 10 + tmp] = 1;

		}

		for (j = 0; j < 10; j++) {

			if (flag[j]) flag2[j * 10 + tmp] = 1;

		}

		flag[tmp] = 1;

	}

	int cnt = 0;

	for (i = 0; i < 1000; i++) {

		if (flag3[i]) cnt++;

	}

	printf("%d\n", cnt);

    return;

}





int main(int argc, char* argv[])

{

#if 1

    solve();

#else

    int T; scanf("%d", &T);

    while(T--) {

        solve();

    }

#endif

    return 0;

}
