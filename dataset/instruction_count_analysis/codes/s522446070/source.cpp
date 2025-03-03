#include <iostream>

#include "stdc++.h"

using namespace std;

char a[30][30]= {0};

int q[]= {1,-1,0,0};

int w[]= {0,0,-1,1};

const int inf = 0x3f3f3f3f;

int l;

int h;

int max1=0;

struct node

{

    int x;

    int y;

};

int main()

{

    cin>>h;

    cin>>l;

    for(int i=0; i<h; i++)

    {

        cin>>a[i];

    }

    for(int i=0; i<h; i++)

    {

        for(int j=0; j<l; j++)

        {

            if(a[i][j]=='#')

                continue;

            int sum1[25][25]= {0};

            memset(sum1,inf,sizeof(sum1));

            sum1[i][j]=0;

            queue<node>p;

            node r;

            r.x=i;

            r.y=j;

            p.push(r);

            while(!p.empty())

            {

                node t=p.front();

                p.pop();

                for(int h1=0; h1<4; h1++)

                {

                    int z=t.x+q[h1];

                    int x=t.y+w[h1];

                    if(z<h&&z>=0&&x<l&&x>=0&&a[z][x]=='.'&&sum1[z][x]==inf)

                    {

                        sum1[z][x]=sum1[t.x][t.y]+1;

                        node u;

                        u.x=z;

                        u.y=x;

                        p.push(u);

                    }

                }

            }

            for(int i2=0;i2<h;i2++)

            {

                for(int j2=0;j2<l;j2++)

                {

                    if(sum1[i2][j2]!=inf)

                    {

                        max1=max(max1,sum1[i2][j2]);

                    }

                }

            }

        }

    }

    cout<<max1<<endl;

    return 0;

}
