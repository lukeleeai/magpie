#include<cstdio>

#include<cstring>

#include<algorithm>

struct abc {

	int aa, bb, cc;

	bool operator < (const abc&T) const {

		return(aa < T.aa || (aa == T.aa && bb < T.bb) || (aa == T.aa && bb == T.bb && cc < T.cc));

	}

	bool operator == (const abc&T) const {

		return(aa == T.aa && bb == T.bb);

	}

} ans[200005];

using namespace std;

int N, KK, LL, i, j, k, l, m, n, pt1[200005], pt2[200005], s1[200005], s2[200005], z;

int sz[200005], ans2[200005];

int find1(int aa) {

	if(pt1[aa] != aa) 

		pt1[aa] = find1(pt1[aa]);

	return(pt1[aa]);

}

int find2(int bb) {

	if(pt2[bb] != bb) 

		pt2[bb] = find2(pt2[bb]);

	return(pt2[bb]);

}

int main() {

	scanf("%d%d%d", &N, &KK, &LL);

	for(i = 1; i <= N; i++) {

		pt1[i] = i;

		pt2[i] = i;

		s1[i] = 1;

		s2[i] = 1;

	}

	for(i = 0; i < KK; i++) {

		scanf("%d%d", &j, &l);

		if(find1(j) == find1(l)) continue;

		s1[find1(l)] += s1[find1(j)];

		pt1[find1(j)] = find1(l);

	}

	

	for(i = 0; i < LL; i++) {

		scanf("%d%d", &j, &l);

		if(find2(j) == find2(l)) continue;

		s2[find2(l)] += s2[find2(j)];

		pt2[find2(j)] = find2(l);

	}

	for(i = 1; i <= N; i++) {

		pt1[i] = find1(i);

		pt2[i] = find2(i);

		ans[i].aa = pt1[i];

		ans[i].bb = pt2[i];

		ans[i].cc = i;

	}

//	for(i = 1; i <= N; i++) printf("%d %d\n", pt1[i], pt2[i]);

	

	sort(ans + 1, ans + N + 1);

	sz[1] = 1;

	for(i = 2; i <= N; i++) if(ans[i] == ans[i - 1]) {

		sz[i] = sz[i - 1] + 1;

	} else {

		sz[i] = 1;

	}

	for(i = N - 1; i >= 1; i--) 

	if(ans[i] == ans[i + 1]) sz[i] = sz[i + 1];

	

	//for(i = 1; i <= N; i++) printf("%d %d %d %d\n", ans[i].aa, ans[i].bb, ans[i].cc, sz[i]);

	

	for(i = 1; i <= N; i++) ans2[ans[i].cc] = sz[i];

	

	for(i = 1; i < N; i++) printf("%d ", ans2[i]);

	printf("%d\n", ans2[N]);

}