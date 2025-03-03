#include<cstdio>

using namespace std;

const int maxn = 100000;

int n, m, qu;

struct node

{

	int nxt;

	int to;

}edge[2 * maxn + 10];

int head[maxn + 10];

int top;

void add_e(const int &u, const int &v)

{

	++top;

	edge[top].nxt = head[u];

	edge[top].to = v;

	head[u] = top;

	return ;

}



int ques[maxn + 10][3];

bool ok[maxn + 10][20];

int q[maxn + 10][3];

int he, ta;

int color[maxn + 10];



void bfs(const int &p)

{

	++ta;

	q[ta][0] = ques[p][0];

	q[ta][1] = ques[p][1];

	q[ta][2] = ques[p][2];

	while(he != ta)

	{

		++he;

		if(ok[q[he][0]][q[he][1]])

			continue;

		if(color[q[he][0]] == 0)

			color[q[he][0]] = q[he][2];

		for(int i = 0; i <= q[he][1]; ++i)

		{

			ok[q[he][0]][i] = 1;

		}

		if(q[he][1] == 0)

			continue;

		for(int i = head[q[he][0]]; i; i = edge[i].nxt)

		{

			if(ok[edge[i].to][q[he][1] - 1])

				continue;

			++ta;

			q[ta][0] = edge[i].to;

			q[ta][1] = q[he][1] - 1;

			q[ta][2] = q[he][2];

			

		}

	}

	return ;

}



int main()

{

	scanf("%d%d", &n, &m);

	int a, b;

	for(int i = 1; i <= m; ++i)

	{

		scanf("%d%d", &a, &b);

		add_e(a, b);

		add_e(b, a);

	}

	scanf("%d", &qu);

	for(int i = 1; i <= qu; ++i)

	{

		scanf("%d%d%d", &ques[i][0], &ques[i][1], &ques[i][2]);

	}

	for(int i = qu; i > 0; --i)

	{

		he = 0;

		ta = 0;

		bfs(i);

	}

	for(int i = 1; i <= n; ++i)

		printf("%d\n", color[i]);

	return 0;

}