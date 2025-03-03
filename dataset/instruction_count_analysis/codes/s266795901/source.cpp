#include <stdio.h>

#include <vector>

#include <queue>

#include <string.h>

using namespace std;



int d[200005];

const int inf = 200005;

vector<int> v[200005];



void bfs(void)

{

    d[1] = 0;



    queue<int> q;



    q.push(1);



    while (!q.empty())

    {

        int t = q.front();q.pop();



        for (int i = 0;i < v[t].size();i++)

        {

            int tt = v[t][i];



            if (d[t] + 1 < d[tt])

            {

                d[tt] = d[t] + 1;



                q.push(tt);

            }

        }

    }

}



int main()

{

    memset(d,inf,sizeof(d));



    int n,m;



    scanf("%d%d",&n,&m);



    for (int i = 1;i <= m;i++)

    {

        int a,b;



        scanf("%d%d",&a,&b);



        v[a].push_back(b);

    }



    bfs();



    if (d[n] == 2) printf("POSSIBLE\n");

    else printf("IMPOSSIBLE\n");



    return 0;

}
