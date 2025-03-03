

#include <iostream>

#include <cstdio>

#include <cmath>

#include <queue>

#include <map>

#include <cstring>

#include <string>

#include <set>

#include <vector>

#include <list>

#include <deque>

#include <algorithm>

#include <stack>

#include <numeric>

#include <time.h>

#include<iomanip>

#pragma warning(disable:4996)

using namespace std;

const int inf = 0x7f7f7f7f;

const long long mod = 1e9 + 7;

pair<int, int>q[120000];

set<int>p[120000];

map<int, int>a;

int main()

{

	int n, m;

	cin >> n >> m;

	set<int>::iterator iter;

	map<int, int>::iterator it;

	for (int i = 0; i < m; i++)

	{

		cin >> q[i].first >> q[i].second;

		p[q[i].first].insert(q[i].second);

	}

	for (int i = 1; i <=n; i++)

	{

		int k = 1;

		for (iter = p[i].begin(); iter != p[i].end(); iter++)

			a[*iter] = k++;

	}

	for (int i = 0; i < m; i++)

	{

		printf("%06d", q[i].first);

		it = a.find(q[i].second);

		printf("%06d\n", it->second);

	}

}

// 运行程序: Ctrl + F5 或调试 >“始执行(不调试)”菜单

// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示:

//   1. 使用解决方案资源管理器窗口添 加/管理文件

//   2. 使用团队资源管理器窗口连接到源代码管理

//   3. 使用输出窗口查看生成输出和其他消息

//   4. 使用错误列表窗口查看错误

//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目

//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件