#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<vector>

using namespace std;

vector<int> p[200010];

int main()

{

    int n,m,i,j,k,x,y,flag=0;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)

    {

        scanf("%d%d",&x,&y);

        p[x].push_back(y);

        p[y].push_back(x);

    }

    for(i=0;i<p[1].size();i++)

    {

        k=p[1][i];

        for(j=0;j<p[k].size();j++)

        if(p[k][j]==n)

        {

            flag=1;

            break;

        }

    }

    if(flag)

        printf("POSSIBLE\n");

    else

        printf("IMPOSSIBLE\n");

    return 0;

}
