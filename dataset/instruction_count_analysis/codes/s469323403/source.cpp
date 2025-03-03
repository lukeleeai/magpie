#include"stdc++.h"

#define st first

#define nd second

using namespace std;

using pii = pair<int,int>;

int bz = 2e5;

pii p[(int)2e5 + 10];

long long bit[(int)2e5 + 10];

void update(int pos, long long val){

    for(;pos <= bz; pos += pos & -pos){

        bit[pos]+=val;

    }

    return;

}

long long query(int pos){

    long long sum = 0LL;

    for(;pos > 0;pos-=pos&-pos){

        sum+=bit[pos];

    }

    return sum;

}

int main(){

    int n,d,a;

    scanf("%d%d%d",&n,&d,&a);

    bz = n;

    for(int i =1;i<=n;i++){

        scanf("%d%d",&p[i].st,&p[i].nd);

    }

    sort(p+1,p+n+1);

    int ti = 0,to = -1,it = 1;

    long long ans = 0LL;

    p[0] ={0,0};

    for(int i =1;i<=n;i++){

        update(i, 1LL *( p[i].nd - p[i-1].nd));

        long long x = query(i);

        if(x <= 0LL) continue;

        int dis = p[i].st + 2 * d;

        for(it = max(it,i);it <= n && p[it].st <= dis;it++);

        ti = x/a + (x % a > 0);

        update(i,1LL * -1 * ti * a);

        if(it <= n) update(it,1LL * ti * a);

        ans += 1LL * ti;

    }

    printf("%lld",ans);



}
