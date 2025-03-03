#include<iostream>

#include<cstring>

#include<cstdio>

#include<vector>

#include<queue>

#include<algorithm>

#include<list>

using namespace std;



const int maxn = 100000;

const int infly = (1<<29);



vector <int> G[maxn+5];

list <int> out;

bool c[maxn];

int N;

int indge[maxn];



void bfs(int s)

{

    queue <int> q;

    q.push(s);

    c[s] = true;



    while( !q.empty() )

    {

        int u = q.front();

        q.pop();

        out.push_back(u);



        for(int i = 0 ; i < G[u].size() ; i++)

        {

            int v = G[u][i];

            indge[v]--;

            if(indge[v] == 0 && !c[v])

            {

                c[v] = true;

                q.push(v);

            }

        }

    }

}



void tsort()

{

    for(int i = 0 ;i < N ;i++)

    {

        indge[i] = 0;

    }



    for(int u = 0; u < N ; u++)

    {

        for(int i = 0 ;i < G[u].size(); i++)

        {

            int v = G[u][i];

            indge[v]++;

        }

    }



    for(int u = 0; u < N ;u++)

    {

        if( indge[u] == 0 && !c[u])

        {

            bfs(u);

        }

    }



    for(list<int> ::iterator it = out.begin(); it != out.end() ;it++)

    {

        cout << *it << endl;

    }

}



int main()

{

    int s, t, M;



    scanf("%d%d",&N,&M);



    for(int i = 0; i < N; i++) c[i] = false;



    for(int i = 0; i < M; i++)

    {

        scanf("%d%d",&s,&t);

        G[s].push_back(t);

    }



    tsort();



    return 0;

}