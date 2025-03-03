#include<stdio.h>

#include<iostream>

#include<algorithm>

#include<string>

#include<queue>

#include<vector>

#include<utility>

#include<math.h>

#include<set>

#include<map>

#include<string.h>

#include<stack>

#define n 200000

#define loop(i, a, b) for(int i = a; i<=b; i++)

using namespace std;

typedef pair<int, int> P;

typedef long long lli;

typedef double llf;

struct edge{

	int from, to, weight;

	bool operator < (const edge& thing) const

	{

		return thing.weight < weight;

	}

};

vector<edge> V[n + 50];

bool visit[n + 50];

int arr[n + 50], a, b, c, d, e;

string str1, str2;

void addedge(int a, int b, int c)

{

	edge temp;

	temp.from = a;

	temp.to = b;

	temp.weight = c;

	V[a].push_back(temp);

}





//////////////////////////////////////////





void solve()

{

	cin >> a;

	loop(i, 0, a - 1)

		cin >> arr[i];

	int max = 0;

	loop(i, 1, a - 1)

		if(arr[i] > arr[max]) max = i;

	int ans2 = -1;

	int temp = arr[max] / 2;

	loop(i, 0, a - 1)

	{

		if(i == max) continue;

		else if(ans2 == -1) ans2 = i;

		else

		{

			int t1 = abs(temp - arr[ans2]), t2 = abs(temp - arr[i]);

			if(t2 < t1) ans2 = i;

		}

	}

	cout << arr[max] << ' ' << arr[ans2] << '\n';

}

int main()

{

	int times = 1;

//	cin << times;

	loop(i, 1, times)

	{

		solve();

		printf("\n");

	}

	return 0;

}




