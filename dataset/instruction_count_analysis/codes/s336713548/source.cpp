#include <cmath>

#include <queue>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>

#define il inline 

#define re register

#define LL long long

using namespace std;

const int maxn = 1e6 + 50;

const int mod = 998244353;

const int INF = (1 << 30);

LL read() {

    LL res = 0, f = 1; char ch = ' ';

    while (!isdigit(ch)) { ch = getchar(); if (ch == '-') f = -1; } 

    while (isdigit(ch)) res = (res << 3) + (res << 1) + ch - '0', ch = getchar();

    return res * f;

}



int n, k;

struct node { int x, dis; };

deque<node> q;

int flag[maxn];

void BFS() {

	while (!q.empty()) q.pop_front();

	q.push_front({1, 1});

	while (!q.empty()) {

		node x = q.front(); q.pop_front();

		if (flag[x.x]) continue;

		flag[x.x] = 1;

		if (!x.x) {

			printf("%d\n", x.dis);

			return;

		}

		q.push_front({x.x * 10 % k, x.dis});

		q.push_back({(x.x + 1) % k, x.dis + 1});

	}

}		

int main() {

	k = read();

	BFS();

	return 0;

}