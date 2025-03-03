#include <cstdio>

using namespace std;

#define MAX 100001

#define NIL -1



struct Node

{

  int parent, left, right;

};



Node TREE[MAX];

int n, DEP[MAX];



void print(int u)

{

  int i, c;

  printf("node %d: ", u);

  printf("parent = %d, ", TREE[u].parent);

  printf("depth = %d, ", DEP[u]);



  if (TREE[u].parent == NIL)

    printf("root, [");

  else if (TREE[u].left == NIL)

    printf("leaf, [");

  else

    printf("internal node, [");



  for (int i = 0, c = TREE[u].left; c != NIL; i++, c = TREE[c].right)

  {

    if (i)

      printf(", ");

    printf("%d", c);

  }

  printf("]\n");

}



void setDepth(int u, int p)

{

  DEP[u] = p;

  if (TREE[u].right != NIL)

    setDepth(TREE[u].right, p);

  if (TREE[u].left != NIL)

    setDepth(TREE[u].left, p + 1);

}



int main()

{

  int n, child;

  scanf("%d", &n);



  for (int i = 0; i < n; i++)

    TREE[i].parent = TREE[i].left = TREE[i].right = NIL;



  for (int i = 0; i < n; i++)

  {

    int id, k, childId;

    scanf("%d%d", &id, &k);

    for (int j = 0; j < k; j++)

    {

      scanf("%d", &childId);

      if (j == 0)

        TREE[id].left = childId;

      else

        TREE[child].right = childId;

      child = childId;

      TREE[childId].parent = id;

    }

  }



  int root;

  for (int i = 0; i < n; i++)

    if (TREE[i].parent == NIL)

      root = i;



  setDepth(root, 0);



  for (int i = 0; i < n; i++)

    print(i);



  return 0;

}