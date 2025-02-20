#include <cstdio>

#include <algorithm>

#include <vector>



using namespace std;



typedef long long lint;



int main()

{

	int n;

	static int a[100000];

	static int s[200000], t[200000], next[2][200000];

	static pair<int, int> p[400000];

	static vector<int> bucket[300000];

	

	lint sum = 0;

	

	scanf("%d", &n);

	

	for (int i = 0; i < n; i++){

		scanf("%d", a + i);

		sum += a[i];

	}

	

	lint left = 0, right = sum / 3;

	

	while (left != right){

		lint mid = (left + right + 1) >> 1;

		lint sum2 = 0;

		int head = 0, tail = 0;

		bool ng = false;

		

		for (; head < n; head++){

			while (sum2 < mid){

				sum2 += a[tail++];

				if (tail >= n) tail -= n;

			}

			int i = head;

			s[i] = head, t[i] = tail;

			if (s[i] == t[i]) ng = true;

			if (t[i] < s[i]) t[i] += n;

			s[n + i] = s[i] + n, t[n + i] = t[i] + n;

			sum2 -= a[head];

		}

		if (ng){

			right = mid - 1;

			continue;

		}

		for (int i = 0; i < n * 3; i++) bucket[i].clear();

		

		for (int i = 0; i < n * 2; i++){

			bucket[t[i]].push_back(i);

			bucket[s[i]].push_back(n * 2 + i);

		}

		int ctr = 0;

		for (int i = 0; i < n * 3; i++){

			for (int j = 0; j < bucket[i].size(); j++){

				p[ctr++] = make_pair(i, bucket[i][j]);

			}

		}

		

		int last = -1;

		for (int i = n * 4 - 1; i >= 0; i--){

			int id = p[i].second;

			if (id < n * 2) next[0][id] = last;

			else {

				id -= n * 2;

				if (last < 0 || t[last] > t[id]) last = id;

			}

		}

		

		for (int k = 0; k + 1 < 2; k++){

			for (int i = 0; i < n * 2; i++){

				if (next[k][i] < 0) next[k + 1][i] = -1;

				else next[k + 1][i] = next[k][next[k][i]];

			}

		}

		

		int res = 0;

		for (int i = 0; i < n; i++){

			int tmp = 0, j = i;

			for (int k = 1; k >= 0; k--){

				int j2 = next[k][j];

				if (j2 >= 0 && t[j2] <= s[i] + n){

					j = j2;

					tmp |= 1 << k;

				}

			}

			if (res >= 3) break;

			res = max(res, tmp + 1);

		}

		if (res >= 3) left = mid;

		else right = mid - 1;

	}

	

	printf("%lld\n", left);

	

	return (0);

}