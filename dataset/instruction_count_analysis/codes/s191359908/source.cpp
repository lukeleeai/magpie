#include <cstdio>

#include <array>



std::array<int, 100005> p;

std::array<int, 100005> fa;



int find(int x)

{

    if (fa[x] != x)

    {

        fa[x] = find(fa[x]);

        return fa[x];

    }

    else

    {

        return x;

    }

}



int main()

{

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)

    {

        scanf("%d", &p[i]);

        fa[i] = i;

    }

    int u, v;

    for (int i = 0; i < m; ++i)

    {

        scanf("%d %d", &u, &v);

        fa[find(u)] = find(v);

    }



    int count = 0;

    for (int i = 1; i <= n; ++i)

    {

        if (find(p[i - 1]) == find(i))

        {

            count++;

        }

    }

    printf("%d\n", count);

}
