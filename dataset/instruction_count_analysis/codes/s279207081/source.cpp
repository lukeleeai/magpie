#include<cstdio>

#include<vector>

#include<algorithm>

using namespace std;



#define ran 555



int n, lim;

int a[ran];

long long pre[ran], suf[ran];

int rem[ran], nr;



bool chk(int mo) {

	/*int reqd = 0;

	vector<int> v;

	for(int i = 0; i < n; i++)

	{

		int cur = a[i] % x;

		v.push_back(cur);

	}

	sort(v.begin(), v.end());

	int l = 0, r = v.size() - 1;

	int rem = 0;

	while(l <= r)

	{

		if(rem <= 0)

		{

			rem += v[l];

			reqd += v[l];

			l++;

		}

		else

		{

			rem -= (x - v[r]);

			reqd += (x - v[r]);

			r--;

		}

	}

	if(reqd > 2 * lim)

		return 0;

	if(rem != 0)

		return 0;

	return 1;*/

	

	nr = 0;

	for(int i=0;i<n;i++) {

		if (a[i] % mo) rem[nr++] = a[i]%mo;

	}

	if (!nr) return true;

	sort(rem, rem+nr);

	

	int mi = 2e9;

	for(int i=0;i<nr;i++) {

		pre[i] = rem[i];

		if(i>0) pre[i] += pre[i-1];

	}

	for(int i=nr-1;i>=0;i--) {

		suf[i] = mo - rem[i];

		if(i<nr-1) suf[i] += suf[i+1];

	}

	/*if (mo==3) {

		printf("%d\n", nr);

		for(int i=0;i<nr;i++) printf("%d%c", pre[i], i<nr-1 ? ' ' : '\n');	

		for(int i=0;i<nr;i++) printf("%d%c", suf[i], i<nr-1 ? ' ' : '\n');

	}*/

	for(int i=1;i<nr;i++)

		mi = min((long long)mi, max(pre[i-1], suf[i]));

	//if (mi<=lim) printf("%d %d\n", mo, mi);

	return (mi <= lim);

}



int main() {

	scanf("%d%d", &n, &lim);

	int s = 0;

	for(int i=0;i<n;i++) {

		scanf("%d", &a[i]);

		s += a[i];

	}

	

	int ans = 1;

	for(int i=1;i*i<=s;i++) {

		if (s%i) continue;

		if(chk(i)) ans = max(ans, i);

		if(chk(s/i)) ans = max(ans, s/i);

	}

	printf("%d\n", ans);

	

	return 0;

}