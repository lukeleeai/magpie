#include <iostream>

#include <string>

#include <cstdio>

#include <cmath>

#include <cstring>

#define max(x,y) x > y? x: y

using namespace std;



const int maxn = 1011111;

int father[maxn];

int gradfa[maxn];



int find(int x)

{

    if(father[x] == x)

        return x;



    int r = find(father[x]);

    gradfa[x] = gradfa[father[x]] + gradfa[x];



    return father[x] = r;

}



int fix(int x,int y,int z)

{

    int fx = find(x);

    int fy = find(y);

    if(fx ==  fy)

        return z == gradfa[y] - gradfa[x];

    father[fy] = fx;

    gradfa[fy] = gradfa[x] + z - gradfa[y];

    return 1;

}



int main()

{

    int n, m;

    int lose = 1;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)

        father[i] = i;

    for(int i = 1; i <= m; i++)

    {

        int x, y, z;

        cin >> x >> y >> z;



        if(lose)

            lose = fix(x, y, z);

    }



    if(lose)

        cout << "Yes" << endl;

    else

        cout << "No" << endl;

    return 0;

}
