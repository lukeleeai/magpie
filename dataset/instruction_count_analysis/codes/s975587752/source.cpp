#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<string>

#include<cmath>

#include<algorithm>

#include<map>

#include<vector>

#include<queue>

#define LL long long

using namespace std;

const int MaxN = 1e5;

const LL Inf = 1LL << 60;



priority_queue<LL> q2;

priority_queue<LL,vector<LL>,greater<LL> > q1;

LL sum[3 * MaxN + 5],cas[3 * MaxN + 5],a[3 * MaxN + 5];

LL sum2[3 * MaxN + 5],cas2[3 * MaxN + 5];



int main()

{

	LL pp,ans;

	int n;

	while(~scanf("%d",&n)){

		ans = -Inf;

		sum[0] = 0;cas[n] = 0;

		for(int i = 1;i <= n;i++) {

			scanf("%lld",&a[i]);

			sum[i] = sum[i - 1] + a[i];

			q1.push(a[i]);

		}

		for(int i = n + 1;i <= 2 * n;i++) {

			scanf("%lld",&a[i]);

			sum[i] = sum[i - 1] + a[i];

			q1.push(a[i]);

			pp = q1.top();

			cas[i] = cas[i - 1] + pp;

			q1.pop();

		}

		for(int i = 2 * n + 1;i <= 3 * n;i++){

			scanf("%lld",&a[i]);

		}

		sum2[3 * n + 1] = 0;cas2[2 * n + 1] = 0;

		for(int i = 3 * n;i >= 2 * n + 1;i--){

			sum2[i] = sum2[i + 1] + a[i];

			q2.push(a[i]);

		}

		for(int i = 2 * n;i >= n + 1;i--){

			sum2[i] = sum2[i + 1] + a[i];

			q2.push(a[i]);

			pp = q2.top();

			cas2[i] = cas2[i + 1] + pp;

			q2.pop();

		}

		for(int i = n;i <= 2 * n;i++){

			pp = sum[i] - cas[i] - sum2[i + 1] + cas2[i + 1];

			ans = max(pp,ans);

		}

		printf("%lld\n",ans);

	}

	return 0;

}