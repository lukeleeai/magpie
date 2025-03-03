#include <stdio.h>

#include <stdlib.h>

#include <algorithm>



// 全局变量

const int N = 100010 , M = N + N;

int x[N],y[N],id[N],n;



typedef struct ufset *UFset;

struct ufset

{

  int *parent;

  int *root;

};

UFset UFinit(int size)

{

  int e;

  UFset U=(UFset)malloc(sizeof *U);

  U->parent=(int*)malloc((size+1)*sizeof(int));

  U->root=(int*)malloc((size+1)*sizeof(int));

  for(e=1; e<=size; e++)

  {

    U->parent[e]=1;

    U->root[e]=1;

  }

  return U;

}

int UFfind(int e,UFset U)

{

  int i,j = e;

  while(!U->root[j]) j = U->parent[j];

  while(j!=e){

    i = U->parent[e];

    U->parent[e]=j;

    e=i;

  }

  return j;

}

int UFunion(int i,int j,UFset U)

{

  if(U->parent[i]<U->parent[j])

  {

    U->parent[j]+=U->parent[i];

    U->root[i]=0;

    U->parent[i]=j;

    return j;

  }

  else

  {

    U->parent[i]+=U->parent[j];

    U->root[j]=0;

    U->parent[j]=i;

    return i;

  }

}



// 记录优化后的边集数

struct Edge

{

  int u, v, cost;

  bool operator <(const Edge&b) const

  {

    return cost < b.cost;

  }

} edge[M];

int tot;

// 按照X轴排序

bool cmpX(int a, int b)

{

  return x[a] < x[b];

}

// 按照Y轴排序

bool cmpY(int a, int b)

{

  return y[a] < y[b];

}

void add(int c, int a, int b)

{

  edge[tot].cost = c;

  edge[tot].u = a;

  edge[tot++].v = b;

}

int main()

{

  scanf("%d", &n);

  int i;

  for (i = 1; i <= n; ++i)

  {

    scanf("%d%d", x + i, y + i);

    id[i] = i;

  }

  std::sort(id + 1 , id + n + 1, cmpX);

  for (i = 2; i <= n; ++i)

    add(x[id[i]] - x[id[i - 1]], id[i], id[i - 1]);

  std::sort(id + 1 , id + n + 1, cmpY);

  for (i = 2; i <= n; ++i)

    add(y[id[i]] - y[id[i - 1]], id[i], id[i - 1]);

  UFset UFS = UFinit(n);



  // 按照花费排序

  std::sort(edge, edge + tot);

  long long totcost = 0;

  for (i = 0; i < tot; ++i)

  {

    int u = edge[i].u, v = edge[i].v;

    u = UFfind(u,UFS), v = UFfind(v,UFS);

    if (u != v)

    {

      UFunion(u,v,UFS);

      totcost += edge[i].cost;

    }

  }

  printf("%lld\n", totcost);

  return 0;

}