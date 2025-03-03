#include <iostream>

#include <set>

#include <algorithm>

#include <cstring>

#define N 100005



char str[N]; int len, mid;

std::pair<int, int> ops[N]; int opscnt;



inline void merge_ops()

{

	static std::set<int> rs[N];

	for(int i = 0; i < opscnt; ++i)

		rs[ops[i].first].insert(ops[i].second);



	opscnt = 0;

	for(int l = 1; l <= mid; ++l)

	{

		std::set<int> &cur = rs[l];

		if(cur.empty()) continue;



		int r = *cur.begin();

		ops[opscnt++] = std::make_pair(l, r);

		//printf("f->%d %d\n", l, r);

		cur.erase(cur.begin());



		std::set<int> &dest = rs[r + 1];

		if(cur.size() < dest.size())

			for(int i: cur) dest.insert(i);

		else

		{

			for(int i: dest) cur.insert(i);

			dest.swap(cur);

		}

	}

}



inline bool solve()

{

	static int pre[N];

	pre[0] = 0;

	pre[1] = str[1] - 'a';

	for(int i = 2; i <= mid; ++i)

	{

		pre[i] = str[i] - str[i - 1];

		pre[i] = (pre[i] + 26) % 26;

	}



	int k = 1;

	for(int o = 0; o < opscnt; ++o)

	{

		const std::pair<int, int> &cur = ops[o];

		for(; k <= cur.first; ++k)

		{

			pre[k] += pre[k - 1];

			pre[k] = (pre[k] + 26) % 26;

		}

		int d = int(str[len - cur.first + 1]) - pre[cur.first] - 'a';

		pre[cur.first] += d;

		pre[cur.first] = (pre[cur.first] + 26) % 26;

		pre[cur.second + 1] -= d;

		pre[cur.second + 1] = (pre[cur.second + 1] + 26) % 26;

	}

	for(; k <= mid; ++k)

	{

		pre[k] += pre[k - 1];

		pre[k] = (pre[k] + 26) % 26;

	}



	for(int i = 1; i <= mid; ++i)

	{

		if(pre[i] != str[len - i + 1] - 'a')

			return false;

	}

	return true;

}



int main()

{

	int _;

	scanf("%s%d", str + 1, &_);

	len = strlen(str + 1);

	mid = len >> 1;



	opscnt = 0;

	for(int i = 0; i < _; ++i)

	{

		int l, r;

		scanf("%d%d", &l, &r);

		if(l - 1 > (len - r))

		{

			l = len - l + 1;

			r = len - r + 1;

			std::swap(l, r);

		}

		if(r > mid) r = len - r;



		if(l <= r)

			ops[opscnt++] = std::make_pair(l, r);

	}



	merge_ops();



	if(solve()) printf("YES\n");

	else printf("NO\n");



	return 0;

}
