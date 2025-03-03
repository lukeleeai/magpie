#include <iostream>

#include <cstdio>

#define IsDigit(x) ((x) >= '0' && (x) <= '9')

using namespace std;



int n, pos;

int last[200001], parity[200001], cross_edge[100001];

struct Edge{

    int y, prev, dir;

}edge[600000];





int Read(void)

{

    int c, ret(0);

    bool sign(false);

    

    c = getchar();

    while (!IsDigit(c) && c != '-')

        c = getchar();

    c == '-' && (sign = true, c = getchar());

    do

        ret = ret * 10 + c - '0';

    while ((c = getchar()) && IsDigit(c));

    return sign ? -ret : ret;

}





inline void AddBiEdge(const int x, const int y)

{

    edge[pos].y = y;

    edge[pos].prev = last[x];

    last[x] = pos++;

    edge[pos].y = x;

    edge[pos].prev = last[y];

    last[y] = pos++;

    return;

}





int main()

{

    int ance, root_A, root_B;

    

    n = Read();

    pos = 2;

    for (int i = 1; i <= n; ++i) {

        ance = Read();

        if (ance == -1)

            root_A = i;

        else {

            AddBiEdge(i, ance);

            ++parity[ance];

        }

    }

    for (int i = 1; i <= n; ++i) {

        ance = Read();

        if (ance == -1)

            root_B = n + i;

        else {

            AddBiEdge(n + i, n + ance);

            ++parity[n + ance];

        }

    }

    for (int i = 1; i <= n; ++i)

        if ((parity[i] & 1) ^ (parity[n + i] & 1)) {

            printf("IMPOSSIBLE\n");

            return 0;

        }

        else

            if (~parity[i] & 1) {

                AddBiEdge(i, n + i);

                cross_edge[i] = pos - 2;

            }

    AddBiEdge(root_A, root_B);

    for (register int src = 1, curr; src <= n << 1; ++src) {

        while (last[src] && edge[last[src]].dir)

            last[src] = edge[last[src]].prev;

        if (!last[src])

            continue;

        curr = src;

        do {

            while (edge[last[curr]].dir)

                last[curr] = edge[last[curr]].prev;

            edge[last[curr]].dir = 1;

            edge[last[curr] ^ 1].dir = 2;

            curr = edge[last[curr]].y;

        }

        while (curr != src);

    }

    printf("POSSIBLE\n");

    for (int i = 1; i <= n; ++i)

        if (cross_edge[i])

            printf(edge[cross_edge[i]].dir == 1 ? "-1 " : "1 ");

        else

            printf("0 ");

    printf("\n");

    return 0;

}


