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

	int s,k,ans;

	while(~scanf("%d%d",&k,&s)){

		ans = 0;

		for(int i = 0;i <= k;i++)

			for(int j = 0;j <= k;j++)

				if(s - i - j >= 0 && s - i - j <= k) ans++;

		printf("%d\n",ans);

	}

    return 0;

}