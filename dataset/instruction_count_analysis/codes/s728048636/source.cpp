#include <stdio.h>

#include <algorithm>

#include <map>

 

using namespace std;

 

#define FOR(i,a,b) for(int i=a;i<b;i++)

#define REP(i,b) FOR(i,0,b)

#define MP make_pair

     

struct Node{

    Node *l,*r,*p;

    int s,v,m;

    Node():l(NULL),r(NULL),p(NULL){}

    static int Size(Node* x){

        return x?x->s:0;

    }

    static int Mini(Node* x){

        return x?x->m:1145141919;

    }

    Node* Update(){

        s=1+Size(l)+Size(r);

        m=min({v,Mini(l),Mini(r)});

        return this;

    }

    int Pos(){

        if(p&&p->l==this) return -1;

        if(p&&p->r==this) return 1;

        return 0;

    }

    void Rotate(){

        Node *q=p,*c;

        if(Pos()==1){

            c=l;

            l=p;

            p->r=c;

        }else{

            c=r;

            r=p;

            p->l=c;

        }

        if(c) c->p=p;

        p=p->p;

        q->p=this;

        if(p&&p->l==q) p->l=this;

        if(p&&p->r==q) p->r=this;

        q->Update();

    }

    Node* Splay(){

        while(p){

            int a=Pos(),b=p->Pos();

            if(b&&a==b) p->Rotate();

            if(b&&a!=b) Rotate();

            Rotate();

        }

        return Update();

    }

    Node* Idx(int i){

        if(i<Size(l)) return l->Idx(i);

        else if(i>Size(l)) return r->Idx(i-Size(l)-1);

        return Splay();

    }

} d[200000];

 

pair<Node*,Node*> Split(Node* x,int i){

    if(i<0) return MP((Node*)NULL,x);

    x=x->Idx(i);

    Node* c=x->r;

    if(c) c->p=NULL;

    x->r=NULL;

    return MP(x->Update(),c);

}

 

Node* Merge(Node* a,Node* b){

    if(!a||!b) return a?a:b;

    while(a->r) a=a->r;

    b->p=a->Splay();

    a->r=b;

    return a->Update();

}

 

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    Node* w=NULL;

    REP(i,n){

        scanf("%d",&d[i].v);

        w=Merge(w,d[i].Update());

    }

    REP(_,q){

        int x,y,z;

        scanf("%d%d%d",&x,&y,&z);

        if(x==0){

            auto r=Split(w,z);

            auto q=Split(r.first,z-1);

            auto p=Split(q.first,y-1);

            w=Merge(Merge(p.first,q.second),Merge(p.second,r.second));

        }else if(x==1){

            auto q=Split(w,z);

            auto p=Split(q.first,y-1);

            printf("%d\n",p.second->m);

            w=Merge(Merge(p.first,p.second),q.second);

        }else{

            w=w->Idx(y);

            w->v=z;

            w->Update();

        }

    }

}