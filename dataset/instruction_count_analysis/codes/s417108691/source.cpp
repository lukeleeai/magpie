#include<cstdio>

#define MAX 100001

int Tree[MAX];



int findRoot(int x){

  if(Tree[x] == x) return x;

  else{

    int tmp = findRoot(Tree[x]);

    Tree[x] = tmp;

    return tmp;

  }

}



using namespace std;



int main()

{

    int list[MAX];

    int belong[MAX];

   int n,m;

   while(scanf("%d%d",&n,&m)!=EOF){

    for(int i = 1; i <= n; i++){

        scanf("%d", &list[i]);

        Tree[i] = i;

    }

    while(m--){

        int a, b;

        scanf("%d%d", &a, &b);

        int na = findRoot(a);

        int nb = findRoot(b);

        if(na != nb) Tree[na] = nb;

    }

    int ans = 0;

    for(int i = 1; i <= n; i++){

        int t = findRoot(i);

        belong[list[i]] = t;

    }

    for(int i = 1 ; i <= n; i++){

        if(belong[i] == Tree[i])

        ans++;

    }

    printf("%d\n",ans);

   }

    return 0;

}
