

#include <stdio.h>

#include <queue>

using namespace std;



int ifield[1001][1001] = {0};



int main()

{

    queue<int> x,y,longth;

    int n,memlongth,ans;

    int dx1[9] = {-1,-1,-1,0,0,0,1,1,1},dy1[9] = {-1,0,1,-1,0,1,-1,0,1},dx2[3] = {1,0,1},dy2[3] = {0,1,1};

    while(1)

    {

        memlongth = 0;

        char cfield[1010][1010] = {0},N;

        scanf("%d",&n);

        if(n == 0)return 0;

        scanf("%c",&N);

        for(int i = 0; i < n; i++)

        {

            for(int j = 0; j < n + 1; j++)

            {

                ifield[j][i] = 0;

            }

        }

        for(int i = 0; i < n; i++)

        {

            for(int j = 0; j < n + 1; j++)

            {

                scanf("%c",&cfield[j][i]);

                if(cfield[j][i] == '*')

                {

                    x.push(j);

                    y.push(i);

                    longth.push(0);

                    ifield[j][i] = 9;

                }

            }

        }

        for(int i = 0; i < n; i++)

        {

            for(int j = 0; j < n; j++)

            {

                if(ifield[j][i] == 0 && (i == 0 || i == n - 1 || j == 0 || j == n - 1))

                {

                    ifield[j][i] = 1;

                    x.push(j);

                    y.push(i);

                    longth.push(1);

                    memlongth = 1;

                }

            }

        }

        while(x.size())

        {

            for(int i = 0; i < 9; i++)

            {

                if(0 <= x.front() + dx1[i] && x.front() + dx1[i] < n &&

                   0 <= y.front() + dy1[i] && y.front() + dy1[i] < n &&

                   ifield[x.front() + dx1[i]][y.front() + dy1[i]] == 0)

                {

                    ifield[x.front() + dx1[i]][y.front() + dy1[i]] = longth.front() + 1;

                    x.push(x.front() + dx1[i]);

                    y.push(y.front() + dy1[i]);

                    longth.push(longth.front() + 1);

                    memlongth = longth.front() + 1;

                }

            }

            x.pop();

            y.pop();

            longth.pop();

        }

        if(memlongth == 0)ans = 0;

        else ans = memlongth * 2 - 1;

        for(int i = 0; i < n - 1; i++)

        {

            for(int j = 0; j < n - 1; j++)

            {

                if(ifield[j][i]  == memlongth)

                {

                    for(int k = 0; k < 3; k++)

                    {

                        if(ifield[j + dx2[k]][i + dy2[k]] == memlongth);

                        else break;

                        if(k == 2)ans = memlongth * 2;

                    }

                }

            }

        }

        printf("%d\n",ans);

    }

}