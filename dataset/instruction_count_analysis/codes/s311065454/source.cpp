#include <cstdio>

 

#define NIL -1

const int MAX_N = 100000 + 5;

 

struct Node {

  int p, lc, rs;

};

 

Node node[MAX_N];

int n;

int id, k, c;

int d[MAX_N];

 

void setDepth(int i, int num) {

  d[i] = num;

  if (node[i].rs != NIL) setDepth(node[i].rs, num);

  if (node[i].lc != NIL) setDepth(node[i].lc, num + 1);

}

 

int main() {

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {

    node[i].p = node[i].lc = node[i].rs = NIL;

  }

  for (int i = 0; i < n; i++) {

    scanf("%d %d", &id, &k);

    int ls;

    for (int j = 0; j < k; j++) {

      scanf("%d", &c);

      node[c].p = id;

      if (j == 0) node[id].lc = c;

      else node[ls].rs = c;

      ls = c;

    }

  }

 

  for (int i = 0; i < n; i++) {

    if (node[i].p == NIL) {

      setDepth(i, 0);

      break;

    }

  }

   

  for (int i = 0; i < n; i++) {

    printf("node %d: parent = %d, depth = %d, ", i, node[i].p, d[i]);

    if (node[i].p == NIL) printf("root, ");

    else if (node[i].lc == NIL) printf("leaf, ");

    else printf("internal node, ");

    printf("[");

    for (int j = 0, c = node[i].lc; c != NIL; j++, c = node[c].rs) {

      if (j) printf(", ");

      printf("%d", c);

    }

    printf("]\n");

  }

  return 0;

}