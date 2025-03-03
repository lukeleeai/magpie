#include<iostream>

#include<cstring>

#include<string>

using namespace std;

struct node

{

  int data;

  struct node*lchild;

  struct node*rchild;

};

typedef struct node;

typedef node *tree;

tree root;



void in(tree &bt,int n)

{

  if(bt)

  {

    if(n<bt->data)

      in(bt->lchild,n);

    else if(n>bt->data)

      in(bt->rchild,n);

  }

  else

  {

    bt=new node;

    bt->data=n;

    bt->lchild=NULL;

    bt->rchild=NULL;

  }

}

void out1(tree bt)

{

  if(bt)

  {

    out1(bt->lchild);

    cout<<" "<<bt->data;

    out1(bt->rchild);

  }

}

void out2(tree bt)

{

  if(bt)

  {

    cout<<" "<<bt->data;

    out2(bt->lchild);

    out2(bt->rchild);

  }

}

int main()

{

  root=NULL;

  int m;

  cin>>m;

  for(int i=1;i<=m;i++)

  {

    string zl;

    cin>>zl;

    if(zl=="insert")

    {

      int num;

      cin>>num;

      in(root,num);

    }

    else if(zl=="print")

    {

      out1(root);

      cout<<endl;

      out2(root);

      cout<<endl;

    }

  }

  return 0;

}