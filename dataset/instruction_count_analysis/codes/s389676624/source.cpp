#include <cstdio>

#include <cstdlib>



typedef struct{

    int height;

    int parent;

}node;



node* nd;



int top(int key){

    if(nd[key].parent == -1)return key;

    else return top(nd[key].parent);

}



void join(int s, int t){

    int a = top(s);

    int b = top(t);

    if(a==b)return;

    if(nd[a].height<nd[b].height){

        nd[a].parent = b;

    }else{

        nd[b].parent = a;

        if(nd[a].height==nd[b].height)nd[a].height++;

    }

    return;

}



bool isFriend(int s, int t){

    if(top(s)==top(t))return true;

    else return false;

}



int main(){

    int i, n, m, s, t, q;

    scanf("%d %d",&n,&m);



    nd = (node *)malloc(sizeof(node)*n);



    for(i=0;i<n;i++){

        nd[i].height = 1;

        nd[i].parent = -1;

    }



    for(i=0;i<m;i++){

        scanf("%d %d",&s,&t);

        join(s,t);

    }



    scanf("%d",&q);

    for(i=0;i<q;i++){

        scanf("%d %d",&s,&t);

        if(isFriend(s,t))printf("yes\n");

        else printf("no\n");

    }

    return 0;

}


