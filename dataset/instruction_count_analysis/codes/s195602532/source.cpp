#include <iostream>

#include <array>



std::array<int, 100005> p;

std::array<int, 100005> fa;



int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}



int main()

{

    int n, m;

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)

    {

        int temp;

        std::cin >> temp;

        p[i] = temp;

        fa[i] = i;

    }



    for (int i = 0; i < m; ++i)

    {

        int u, v;

        std::cin >> u >> v;



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

    std::cout << count << std::endl;

}
