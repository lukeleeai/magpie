#include"stdc++.h"

using namespace std;

const long long llINF = 9223372036854775807;

const int INF = 2147483647;

const int maxn = 1e5 + 7;

const int maxm = 1e6 + 7;

const int mod = 1e9 + 7;

const double pi = acos(-1.0);

const double eps = 1e-10;

int n;

int fa[maxn];

struct node

{

    long long u, v, w;

};

vector<node> edge;

bool operator<(node a, node b)

{

    return a.w < b.w;

}

struct node2

{

    long long x, y, id;

} city[maxn];



bool cmp1(node2 a, node2 b)

{

    return a.x < b.x;

}



bool cmp2(node2 a, node2 b)

{

    return a.y < b.y;

}

void init()

{

    for (int i = 1; i < maxn; i++)

        fa[i] = i;

}

int get(int x)

{

    return fa[x] == x ? x : fa[x] = get(fa[x]);

}

long long ans;

int main(int argc, char const *argv[])

{

    init();

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)

    {

        scanf("%lld%lld", &city[i].x, &city[i].y);

        city[i].id = i;

    }

    sort(city + 1, city + 1 + n, cmp1);

    for (int i = 1; i < n; i++)

        edge.push_back(node{city[i].id, city[i + 1].id, abs(city[i].x - city[i + 1].x)});



    sort(city + 1, city + 1 + n, cmp2);

    for (int i = 1; i < n; i++)

        edge.push_back(node{city[i].id, city[i + 1].id, abs(city[i].y - city[i + 1].y)});



    sort(edge.begin(),edge.end());



    for(int i=0;i<edge.size();i++)

    {

        int x=get(edge[i].u);

        int y=get(edge[i].v);

        if(x==y)

            continue;

        fa[x]=y;

        ans+=edge[i].w;

    }

    

    printf("%lld\n",ans);

    return 0;

}