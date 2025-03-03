#include <cstdio>

#include <cstdlib>



typedef struct node_{

    int key;

    int height;

    struct node_ *parent;

}node;



node *nd;



node* top(node* nd){

    while(true){

        if(nd->parent==NULL)break;

        nd = nd->parent;

    }

    return nd;

}



void unite(int x, int y){

    node* a = top(nd+x);

    node* b = top(nd+y);

    if(a==b)return;

    if(a->height < b->height){

        a->parent = b;

    }else{

        b->parent = a;

        if(a->height == b->height){

            a->height++;

        }

    }

    return;

}



int same(int x, int y){

    node* a = top(nd+x);

    node* b = top(nd+y);

    if(a==b)return 1;

    else return 0;

}



int main(){

    int i,n,q,x,y,com;

    scanf("%d %d",&n,&q);

    nd = (node *)malloc(sizeof(node)*n);



    for(i=0;i<n;i++){

        nd[i].key = i;

        nd[i].height = 1;

        nd[i].parent = NULL;

    }



    for(i=0;i<q;i++){

        scanf("%d %d %d",&com,&x,&y);

        switch(com){

        case 0://unite

            unite(x,y);

            break;

        case 1://same

            printf("%d\n",same(x,y));

            break;

        default:

            perror("error\n");

            return -1;

            break;

        }

    }

    return 0;

}


