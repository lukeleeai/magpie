#include <cstdio>

#include <algorithm>

#include <queue>

using namespace std;

const int N=200005;

int n,m;

struct People{

    int l,r,id;

    friend bool operator < (People a,People b){

        return a.r>b.r;

    }

}a[N],b[N];

bool inq[N];

int cnt;

priority_queue<People> q;

bool cmpl(const People &a,const People &b){

    return a.l<b.l;

}

bool cmpr(const People &a,const People &b){

    return a.r>b.r;

}

int main(){

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

        scanf("%d%d",&a[i].l,&a[i].r);

    sort(a+1,a+1+n,cmpl);

    int nowl=0,nowr=m+1,last;

    for(int i=1;i<=n;i++){

        a[i].id=i;

        if(nowl+1<=a[i].l){

            nowl++;

            q.push(a[i]);

            inq[i]=true;

        }

        else if(!q.empty()){

            People best=q.top();

            if(a[i].r>best.r){

                q.pop();

                inq[best.id]=false;

                q.push(a[i]);

                inq[i]=true;

            }

        }

    }

    for(int i=1;i<=n;i++)

        if(!inq[i])

            b[++cnt]=a[i];

    sort(b+1,b+1+cnt,cmpr);

    for(int i=1;i<=cnt&&nowr-1!=nowl;i++)

        if(nowr-1>=b[i].r)

            nowr--;

    printf("%d\n",n-(nowl+(m-nowr+1)));

    return 0;

}