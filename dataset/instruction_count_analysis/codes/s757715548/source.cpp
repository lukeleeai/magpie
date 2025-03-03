#include <stdio.h>

#include <cmath>

#include <algorithm>

#include <cfloat>

#include <stack>

#include <queue>

#include <vector>

#include <string>

#include <iostream>

#include <set>

#include <map>

typedef long long int ll;

typedef unsigned long long int ull;

#define BIG_NUM 2000000000

#define MOD 1000000007

#define EPS 0.000000001

using namespace std;

 

struct Node{

    int location;

    int p,left,right;

};

 

struct Point{

    Point(){

        id = x = y = 0;

    }

 

    Point(int arg_id,int arg_x,int arg_y){

        id = arg_id;

        x = arg_x;

        y = arg_y;

    }

    bool operator < (const Point & arg)const{

        return id < arg.id;

    }

    void print(){

        printf("%d\n",id);

    }

    int id,x,y;

};

 

static const int MAX = 1000000;

static const int NIL = -1;

 

int N;

Point P[MAX];

Node T[MAX];

int number;

 

bool lessX(const Point &p1, const Point &p2) {return p1.x < p2.x; }

bool lessY(const Point &p1, const Point &p2) {return p1.y < p2.y; }

 

int makeKDTree(int left,int right, int depth){

 

    if(!(left < right))return NIL;

 

    int mid = (left+right)/2;

 

    int node_id = number++;

 

    if(depth%2 == 0){

        sort(P+left,P+right,lessX);

    }else{

        sort(P+left,P+right,lessY);

    }

 

    T[node_id].location = mid;

    T[node_id].left = makeKDTree(left,mid,depth+1);

    T[node_id].right = makeKDTree(mid+1,right,depth+1);

 

    return node_id;

}

 

void find(int node_id,int sx,int tx,int sy,int ty, int depth, vector<Point> &ans){

 

    int x = P[T[node_id].location].x;

    int y = P[T[node_id].location].y;

 

    if(sx <= x && x <= tx && sy <= y && y <= ty){

        ans.push_back(P[T[node_id].location]);

    }

 

    if(depth%2 == 0){

        if(T[node_id].left != NIL){

            if(sx <= x)find(T[node_id].left,sx,tx,sy,ty,depth+1,ans);

        }

        if(T[node_id].right != NIL){

            if( x <= tx)find(T[node_id].right,sx,tx,sy,ty,depth+1,ans);

        }

    }else{

        if(T[node_id].left != NIL){

            if(sy <= y)find(T[node_id].left,sx,tx,sy,ty,depth+1,ans);

        }

        if(T[node_id].right != NIL){

            if(y <= ty)find(T[node_id].right,sx,tx,sy,ty,depth+1,ans);

        }

    }

}

 

 

int main(){

 

    int x,y;

    scanf("%d",&N);

    for(int i = 0; i < N; i++){

        scanf("%d %d",&x,&y);

        P[i] = Point(i,x,y);

        T[i].left = T[i].right = T[i].p = NIL;

    }

 

    number = 0;

 

    int root = makeKDTree(0,N,0);

 

    int q;

    scanf("%d",&q);

    int sx,tx,sy,ty;

    vector<Point> ans;

    for(int i = 0; i < q; i++){

        scanf("%d %d %d %d",&sx,&tx,&sy,&ty);

        ans.clear();

        find(root,sx,tx,sy,ty,0,ans);

        sort(ans.begin(),ans.end());

        for(int j = 0; j < ans.size(); j++){

            ans[j].print();

        }

        printf("\n");

    }

    return 0;

}
