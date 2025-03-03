#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define NIL -1



struct Node{

    int num;

    struct Node* left;

    struct Node* right;

};



struct Node* root;



void insert(int num, struct Node* n){

    if(root == NULL){

        root = (Node*) malloc(sizeof(struct Node));

        root->num = num;

        root->left = NULL;

        root->right = NULL;

        return;

    }



    if(num < n->num){

        if(n->left == NULL){

            n->left = (Node*) malloc(sizeof(struct Node));

            n->left->num = num;

            n->left->left = NULL;

            n->left->right = NULL;

        }else{

            insert(num, n->left);

        }

    }else{

        if(n->right == NULL){

            n->right = (Node*) malloc(sizeof(struct Node));

            n->right->num = num;

            n->right->left = NULL;

            n->right->right = NULL;

        }else{

            insert(num, n->right);

        }

    }

}



void print_middle(struct Node* n){

    if(n == NULL){

        return;

    }

    print_middle(n->left);

    printf(" %d", n->num);

    print_middle(n->right);

}



void print_before(struct Node* n){

    if(n == NULL){

        return;

    }

    printf(" %d", n->num);

    print_before(n->left);

    print_before(n->right);

}



void init(){

    root = NULL;

}



int main(void){

    init();



    int N;

    scanf("%d", &N);



    for(int i = 0; i < N; i++){

        char comm[100];

        int num;

        scanf("%s", comm);



        if(comm[0] == 'i'){

            scanf("%d", &num);

            insert(num, root);

        }else if(comm[0] == 'p'){

            print_middle(root);

            printf("\n");

            print_before(root);

            printf("\n");

        }

    }

}




