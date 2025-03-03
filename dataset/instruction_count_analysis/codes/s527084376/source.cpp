#include <stdio.h>

#include <string.h>

#include <vector>

#include <queue>

#include <map>

#include <algorithm>

using namespace std;



typedef long long ll;



const int MOD = (int)1e9 + 7;

const int MAXN = (int)1e5 + 5;



char str[MAXN];



int main() {

	scanf("%s", str);

	int len = strlen(str);

	int ans = 0;

	for(int i = len - 2; i >= 0; --i) {

		if(str[i] != str[i + 1]) ++ans;

	}

	printf("%d\n", ans);

	return 0;

}
