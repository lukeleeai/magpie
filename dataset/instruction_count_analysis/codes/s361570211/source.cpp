#include <cstdio>

#include <cstdlib>

#define MAXN 100010

int n,q;

typedef struct p{

    char name[10];

    int time;

}P;

P que[MAXN];

int head,tail,tot;







void get_input() {

    scanf("%d %d",&n,&q);

    for(int i=0;i<n;i++) {

        scanf("%s %d",que[i].name,&que[i].time);

    }

    tail=n;

}



void solve() {

    P item;

    while(head!=tail) {

        item=que[head];

        head=(head+1)%(n+1);

        if(item.time>q) {

            item.time-=q;

            tot+=q;

            que[tail]=item;

            tail=(tail+1)%(n+1);

        } else {

            tot+=item.time;

            printf("%s %d\n",item.name,tot);

        }

    }

}



void display_output() {

    

}



int main() {

#ifdef debug

    freopen("in.txt","r",stdin);

#endif

    get_input();

    solve();

    display_output();

}