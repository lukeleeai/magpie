#include<cstdio>

#include<algorithm>

using namespace std;

const int MAXN = 100;

char s[MAXN + 5];

int cnt1[26], cnt2[26];

int main() {

	int N;

	scanf("%d%s", &N, s);

	for(int i=0;i<N;i++)

		cnt1[s[i]-'a']++;

	int ans = 0, res = 0;

	for(int i=0;i<N-1;i++) {

		cnt2[s[i]-'a']++;

		if( cnt2[s[i]-'a'] == 1 ) ans++;

		if( cnt2[s[i]-'a'] == cnt1[s[i]-'a'] ) ans--;

		res = max(res, ans);

	}

	printf("%d\n", res);

}