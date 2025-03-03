#include<cstdio>

#include<algorithm>

using namespace std;



const int MAXN=2e5 + 100;

typedef pair<int,int> pii;

#define fi first

#define se second



int n,m;

pii q[MAXN];

int cnt[MAXN],f[MAXN],a[MAXN];



int main(){

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=m;i++) scanf("%d%d",&q[i].fi,&q[i].se);

    for(int i=1;i<=n;i++) cnt[a[i]]++;

    for(int i=1;i<=n;i++){

        if(cnt[i])

            for(int j=max(0,i-cnt[i]);j<i;j++)

                f[j]++;

    }

    int ans=0;

    for(int i=0;i<n;i++) if(!f[i]) ans++;

    for(int i=1;i<=m;i++){

        int x=a[q[i].fi],y=q[i].se;

        a[q[i].fi]=y;

        if(x-cnt[x]>=0){

            f[x-cnt[x]]--;

            if(f[x-cnt[x]]==0) ans++;

        }

        cnt[x]--;

        if(y-cnt[y]-1>=0){

            f[y-cnt[y]-1]++;

            if(f[y-cnt[y]-1]==1) ans--;

        }

        cnt[y]++;

        printf("%d\n",ans);

    }

}


