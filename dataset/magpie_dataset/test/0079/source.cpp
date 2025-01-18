#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <queue>

#include <map>

#include <stack>

#include <string>

#include <cmath>

#include <cstdlib>

#include <set>

using namespace std;



#define M 1e9+7

typedef long long ll;

#define  mem(a) memset(a,0,sizeof a)

#define pi acos(-1.0)

#define inf 0x3f3f3f

struct node

{

        int u,v;double w;

}mp[100000];

struct node1

{

        double x,y;

}c[10005];

int n,m;

int f[10005];

bool cmp(node a,node b)

{

        return a.w > b.w;

}

int find(int x)

{

        while(x != f[x])

                x = f[x];

        return x;

}

int main()

{

        while(~scanf("%d %d",&n,&m))

        {

                for(int i = 1 ; i <= n ; i ++)

                        scanf("%lf %lf",&c[i].x,&c[i].y);

                for(int i = 0 ; i < m ; i ++)

                {

                        int a,b;

                        scanf("%d %d",&a,&b);

                        mp[i].u = a;

                        mp[i].v = b;

                        mp[i].w = sqrt ((c[a].x-c[b].x )*(c[a].x-c[b].x) + (c[a].y-c[b].y)*(c[a].y - c[b].y));

                }

                sort(mp,mp+m,cmp);

                double ans = 0;

                for(int i = 1 ; i <= n ; i ++)

                        f[i] = i;

                for(int i = 0 ; i < m ; i ++)

                {

                        int a = mp[i].u;

                        int b = mp[i].v;

                        int fa = find(a);

                        int fb = find(b);

                        if(fa == fb)

                                ans += mp[i].w;

                        else

                        {

                                int mi = min(fa,fb);

                                int ma = max(fa,fb);

                                f[ma] = mi;

                        }

                }

                printf("%.3f\n",ans);

        }





        return 0;

}