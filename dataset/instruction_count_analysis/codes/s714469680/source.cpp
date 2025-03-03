#include <cstdio>

 

char c[15][15],d[15],e[15];

int i,m,n;

 

inline bool dfs2(int x)

{

    if (x>m)

        return true;

    if (e[x])

        return dfs2(x+1);

    else

    {

        int t=0,r=0;

        for (int i=x;i<=m;i++)

            if (! e[i])

                t++;

        for (int i=x;i<=m;i++)

            if (! e[i])

            {

                e[x]=i,e[i]=x,r=1;

                for (int j=1;j<=n;j++)

                    if ((c[j][x]!=c[d[j]][i]) || (c[d[j]][x]!=c[j][i]))

                    {

                        r=0;

                        break;

                    }

                if(i==x){

                    if(r&&(t&1)&&dfs2(x+1))return true;

                }

                else{

                    if(r){

                        if(dfs2(x+1))return true;else return false;

                    }

                }

                /*if ((r) && ((t&1) || (i!=x)) && (dfs2(x+1)))

                    return true;

                else if(i!=x)return false;*/

                e[x]=0,e[i]=0;

            }

    }

    return false;

}

 

inline bool dfs1(int x)

{

    if (x>n)

        return dfs2(1);

    if (d[x])

        return dfs1(x+1);

    else

    {

        int t=0;

        for (int i=x;i<=n;i++)

            if (! d[i])

                t++;

        for (int i=x;i<=n;i++)

            if (! d[i])

            {

                d[x]=i,d[i]=x;

                if (((t&1) || (i!=x)) && (dfs1(x+1)))

                    return true;

                d[x]=0,d[i]=0;

            }

    }

    return false;

}



int main()

{

    scanf("%d%d",&n,&m);

    for (i=1;i<=n;i++)

        scanf("%s",c[i]+1);

    if (dfs1(1))

        puts("YES");

    else

        puts("NO");

    return 0;

}