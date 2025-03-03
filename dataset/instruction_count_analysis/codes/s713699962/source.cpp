//yhn's

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<vector>

using namespace std;



typedef long long ll;

const int MAXN=2e5+5;



int n;

int fa[MAXN];

ll d,siz[MAXN],cnt[MAXN];

vector<pair<ll,int> > mp;

struct node{

    ll x,y;

    int id;

    bool operator < (const node &a) const{

        if(x==a.x) return y<a.y;

        return x<a.x;

    }

}p[MAXN];



int find(int x){

    if(fa[x]==x) return x;

    return fa[x]=find(fa[x]);

}



ll dis(int x,int y){

    return abs(p[x].x-p[y].x)+abs(p[x].y-p[y].y);

}



void work(int now){

    mp.clear();

    vector<pair<ll,int> >::iterator lasx,it;

    int las=1,flag=0;

    for(int i=1;i<=n;i++){

        if(p[i].x!=p[i-1].x){

            mp.clear();

            flag=1;

        }

        while(p[i].x-p[las].x>d&&las<=n) las++;

        while(p[i].x-p[las].x==d&&las<=n){

            mp.push_back(make_pair(p[las].y,p[las].id));

            las++;

        }

        it=lower_bound(mp.begin(),mp.end(),make_pair(p[i].y-d+now,0));

        if(it==mp.end()||it->first>p[i].y+d-now) continue;

        if(flag){

            flag=0;

            lasx=mp.begin();

        }

        lasx=max(lasx,it);

        for(;lasx!=mp.end()&&lasx->first<=p[i].y+d-now;lasx++){

            int x=lasx->second;

            int y=p[i].id;

            if(find(x)!=find(y))

                fa[find(x)]=find(y);

        }

        cnt[p[i].id]+=lasx-it;

        if(lasx!=it) lasx--;

    }

}



int main(){

    int a,b;

    scanf("%d%d%d",&n,&a,&b);

    for(int i=1;i<=n;i++)

        scanf("%lld%lld",&p[i].x,&p[i].y),p[i].id=i;

    for(int i=1;i<=n;i++) fa[i]=i;

    d=dis(a,b);

    for(int i=1;i<=n;i++){

        int x=p[i].x,y=p[i].y;

        p[i].x=x-y;

        p[i].y=x+y;

    }

    sort(p+1,p+n+1);

    work(0);

    for(int i=1;i<=n;i++)

        swap(p[i].x,p[i].y);

    sort(p+1,p+n+1);

    work(1);

    for(int i=1;i<=n;i++)

        siz[find(i)]+=cnt[i];

    printf("%lld",siz[find(a)]);

}
