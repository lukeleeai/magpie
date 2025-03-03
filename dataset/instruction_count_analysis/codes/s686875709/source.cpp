    #include "stdc++.h"

    using namespace std;

    typedef long long LL;

     

    const int RLEN=1<<18|1;

    inline char nc() {

        static char ibuf[RLEN],*ib,*ob;

        (ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));

        return (ib==ob) ? -1 : *ib++;

    }

    inline int rd() {

        char ch=nc(); int i=0,f=1;

        while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}

        while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}

        return i*f;

    }

     

    const int N=1e5+50;

    int n,m,stx,sty,dep[N],fa[N],s[N];

    vector <int> edge[N]; LL ans=0;

    inline void dfs(int x,int f,int val) {

        dep[x]=dep[f]+1; fa[x]=f; s[x]=val;

        for(auto v:edge[x]) {

            if(v!=f) {

                if(dep[v]) stx=x, sty=v;

                else dfs(v,x,-val), s[x]+=s[v];

            }

        }

    }

    inline int lca(int x,int y) {

        while(dep[x]>dep[y]) x=fa[x];

        while(dep[x]<dep[y]) y=fa[y];

        while(x!=y) x=fa[x], y=fa[y];

        return x;

    }

    int main() {

        n=rd(), m=rd();

        for(int i=1;i<=m;i++) {

            int x=rd(), y=rd();

            edge[x].push_back(y);

            edge[y].push_back(x);

        } dfs(1,0,1);

        if(m==n-1) {

            if(s[1]) {puts("-1"); return 0;}

            for(int i=1;i<=n;i++) ans+=abs(s[i]);

        } else {

            if((dep[stx]-dep[sty])&1) { // even circle

                if(s[1]) {puts("-1"); return 0;}

                static int a[N],tot;

                int l=lca(stx,sty);

                for(int u=stx;u!=l;u=fa[u]) a[++tot]=s[u],dep[u]=-1;

                for(int u=sty;u!=l;u=fa[u]) a[++tot]=-s[u],dep[u]=-1;

                a[++tot]=0; int mid=tot/2+1;

                nth_element(a+1,a+mid,a+tot+1);

                int z=a[mid];

                for(int i=1;i<=n;i++) if(~dep[i]) ans+=abs(s[i]);

                for(int i=1;i<=tot;i++) ans+=abs(a[i]-z);

            } else {

                if(s[1]&1) {puts("-1"); return 0;}

                int z=-s[1]/2; ans+=abs(z);

                for(int u=stx;u;u=fa[u]) s[u]+=z;

                for(int u=sty;u;u=fa[u]) s[u]+=z;

                for(int i=1;i<=n;i++) ans+=abs(s[i]);

            }

        } cout<<ans<<'\n';

    }