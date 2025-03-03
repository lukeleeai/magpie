#include <cstdio>

#include <vector>

#include <string>

using namespace std;



struct Node

{

  int id;

  int parent;

  vector<int> children;

};



int getDepth(Node t[], Node n)

{

  int count = 0;

  Node node = n;

  while (node.parent != -1)

  {

    count++;

    node = t[node.parent];

  }

  return count;

}



int main()

{

  int n;

  scanf("%d", &n);



  Node tree[100000];

  for (int i = 0; i < 100000; i++)

    tree[i] = {-100, -1, {}};



  for (int i = 0; i < n; i++)

  {

    int id, k, tmp;

    scanf("%d%d", &id, &k);

    tree[id].id = id;

    for (int j = 0; j < k; j++)

    {

      scanf("%d", &tmp);

      tree[id].children.push_back(tmp);

      tree[tmp].parent = id;

    }

  }



  for (int i = 0; i < 100000; i++)

  {

    Node node = tree[i];

    if (node.id != -100)

    {

      string type = node.parent == -1 ? "root" : (node.children.size() == 0 ? "leaf" : "internal node");

      printf("node %d: parent = %d, depth = %d, %s, [",

             node.id, node.parent, getDepth(tree, node), type.c_str());

      int size = node.children.size();

      for (int j = 0; j < size; j++)

      {

        if (j != 0)

          printf(", ");

        printf("%d", node.children[j]);

      }

      printf("]\n");

    }

  }

  return 0;

}