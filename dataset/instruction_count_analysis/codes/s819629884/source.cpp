#include<stdio.h>

#include<map>

#include<string>

#include<string.h>

#include<utility>

#include<algorithm>

#include<vector>

#include<queue>

#include<iostream>

#include<math.h>

#include<stack>

#include<set>

#define INF 2147483647

#define loop(i, a, b) for(int i=a; i<=b; i++)

#define mem(arr) memset(arr, 0, sizeof(arr));

using namespace std;

typedef long long lli;

typedef double llf;

typedef pair<int, int> P;

typedef vector<int> vec;

typedef priority_queue<int, vector<int>, greater<int> > pQ;

typedef queue<int> Q;

typedef set<int> S;

struct edge{

	int to, value;

};

void solve();

int main()

{

	int times = 1;

//	cin >> times;

	loop(i, 1, times)

	{

		solve();

		cout << '\n';

	}

	return 0;

}

const int n = 2e5;

vector<edge> tree[n + 50];

int a, b, c, d, e, f;

int arr[n + 50], arr1[n + 50], arr2[n + 50];

string str, str1, str2;



void solve()

{

	cin >> a;

	cin >> str;

	stack<char> S;

	S.push(str[0]);

	int cnt = 1;

	for(int i=1; i<a; i++)

	{

		if(str[i] == S.top()) continue;

		else

		{

			cnt ++;

			S.push(str[i]);

		}

	}

	cout << cnt << '\n';

}